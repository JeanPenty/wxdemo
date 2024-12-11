
#include <souistd.h>
#include <animation/STransformation.h>

SNSBEGIN

bool STransformation::isIdentity() const
{
    return getTransformationType() == TYPE_IDENTITY;
}

bool STransformation::hasMatrix() const
{
    return (getTransformationType() & TYPE_MATRIX) == TYPE_MATRIX;
}

bool STransformation::hasAlpha() const
{
    return (getTransformationType() & TYPE_ALPHA) == TYPE_ALPHA;
}

BYTE STransformation::GetAlpha() const
{
    return mAlpha;
}

void STransformation::updateMatrixType()
{
    if (mMatrix.isIdentity())
        mTransformationType &= ~TYPE_MATRIX;
    else
        mTransformationType |= TYPE_MATRIX;
}

void STransformation::SetAlpha(BYTE alpha)
{
    mAlpha = alpha;
    mTransformationType |= TYPE_ALPHA;
}

void STransformation::setMatrix(const SMatrix &mtx)
{
    mMatrix = mtx;
    updateMatrixType();
}

SMatrix &STransformation::getMatrix()
{
    return mMatrix;
}

const SMatrix &STransformation::getMatrix() const
{
    return mMatrix;
}

void STransformation::postCompose(STransformation t)
{
    if (t.hasAlpha())
    {
        mAlpha = (BYTE)((int)mAlpha * t.GetAlpha() / 255);
        mTransformationType |= TYPE_ALPHA;
    }
    if (t.hasMatrix())
    {
        mMatrix *= t.getMatrix();
        updateMatrixType();
    }
}

void STransformation::Compose(const ITransformation *t)
{
    const STransformation &t2 = *(const STransformation *)t;
    compose(t2);
}

void STransformation::compose(const STransformation &t)
{
    if (t.hasAlpha())
    {
        mAlpha = (BYTE)((int)mAlpha * t.GetAlpha() / 255);
        mTransformationType |= TYPE_ALPHA;
    }
    if (t.hasMatrix())
    {
        mMatrix = t.getMatrix() * mMatrix;
        updateMatrixType();
    }
}

void STransformation::set(STransformation t)
{
    mAlpha = t.GetAlpha();
    mMatrix = t.getMatrix();

    mTransformationType = t.getTransformationType();
}

void STransformation::SetTransformationType(int type)
{
    mTransformationType = type;
}

int STransformation::getTransformationType() const
{
    return mTransformationType;
}

void STransformation::Clear()
{
    mMatrix.reset();
    mAlpha = 255;
    mTransformationType = TYPE_IDENTITY;
}

STransformation::STransformation()
{
    Clear();
}

IMatrix *STransformation::GetMatrix()
{
    return &mMatrix;
}

SNSEND