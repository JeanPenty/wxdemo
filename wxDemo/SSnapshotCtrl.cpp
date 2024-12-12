#include "stdafx.h"
#include "SSnapshotCtrl.h"

SSnapshotCtrl::SSnapshotCtrl(void)
{
	m_bCapture = false;

	m_emPosType = Null;
}

SSnapshotCtrl::~SSnapshotCtrl(void)
{
}

void SSnapshotCtrl::OnPaint(IRenderTarget* pRT)
{
	HDC hDC = pRT->GetDC(0);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(hDC);
	dcCompatible.SelectBitmap(*m_pBitmap);

	SIZE szBMP;
	m_pBitmap->GetSize(szBMP);
	CRect rcWindow(0, 0, szBMP.cx, szBMP.cy);

	BitBlt(hDC, 0, 0, szBMP.cx, szBMP.cy, dcCompatible, 0, 0, SRCCOPY);

	//ªÊ÷∆ª“…´’⁄’÷
	{
		CAutoRefPtr<IPath> path;
		GETRENDERFACTORY->CreatePath(&path);
		path->addRect(rcWindow);

		//CRect rcCapture(200, 200, 1000, 1000);
		pRT->PushClipRect(m_rcCaptureArea, RGN_XOR);

		CAutoRefPtr<IBrush> brush, oldbrush;
		pRT->CreateSolidColorBrush(RGBA(0, 0, 0, 100), &brush);
		pRT->SelectObject(brush, (IRenderObj**)&oldbrush);
		pRT->FillPath(path);
		pRT->SelectObject(oldbrush, NULL);
	}
}

void SSnapshotCtrl::OnMouseMove(UINT nFlags, SOUI::CPoint point)
{
	if ((nFlags & MK_LBUTTON))
	{
		switch (m_emPosType)
		{
		case Null:
		{
			if (m_bCapture) return;
			if (m_ptDown == point)
				return;

			m_rcCaptureArea.SetRect(m_ptDown, point);
			m_rcCaptureArea.NormalizeRect();
		}
		break;
		case TopLeft:
			break;
		case TopCenter:
			break;
		case TopRight:
			break;
		case RightCenter:
			break;
		case BottomRight:
			break;
		case BottomCenter:
			break;
		case BottomLeft:
			break;
		case LeftCenter:
			break;
		case SelectRect:
			break;
		default:
			break;
		}
	}

	Invalidate();
}

void SSnapshotCtrl::OnLButtonDown(UINT nFlags, SOUI::CPoint point)
{
	SetCapture();
	if (m_rcCaptureArea.IsRectEmpty())
	{
		m_emPosType = Null;
	}
	else if (PtInRect(m_rcCaptureArea, point))
	{
		m_emPosType = SelectRect;
	}

	m_ptDown = point;
}

void SSnapshotCtrl::OnLButtonUp(UINT nFlags, SOUI::CPoint point)
{
	//
	m_bCapture = true;
}

void SSnapshotCtrl::OnLButtonDblClk(UINT nFlags, SOUI::CPoint point)
{
	//
}

void SSnapshotCtrl::OnRButtonUp(UINT nFlags, CPoint point)
{
	//
}

void SSnapshotCtrl::SetBmpResource(CBitmap* pBmp)
{
	m_pBitmap = pBmp;

	//m_vecBitmap.push_back(pBmp);
	Invalidate();
}