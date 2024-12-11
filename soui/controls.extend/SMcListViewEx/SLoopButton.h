#pragma once
#include "core\Swnd.h"

SNSBEGIN

#define EVT_BTNSEL_CHANGING EVT_EXTERNAL_BEGIN + 100
#define EVT_BTNSEL_CHANGED  EVT_BTNSEL_CHANGING + 1

DEF_EVT_EXT(EventBtnSelChanging,EVT_BTNSEL_CHANGING,{
	int iOldSel;
	int iNewSel;
	BOOL bCancel;
});

DEF_EVT_EXT(EventBtnSelChanged,EVT_BTNSEL_CHANGED,{
	int iOldSel;
	int iNewSel;
	BOOL bCancel;
});

//һ��
class SLoopButton : public SImageButton {
    DEF_SOBJECT(SImageButton, L"loopbtn")
  public:
    SLoopButton();
    ~SLoopButton();

    SOUI_ATTRS_BEGIN()
    ATTR_INT(L"skinStates", m_iSkinStates, FALSE)
    ATTR_INT(L"curState", m_iCurState, FALSE)
    ATTR_INT(L"states", m_iState, FALSE)
    SOUI_ATTRS_END()

  protected:
    virtual void OnStateChanged(DWORD dwOldState, DWORD dwNewState) override;
    virtual BOOL NeedRedrawWhenStateChange() override
    {
        return m_iSkinStates > 1 ? TRUE : FALSE;
    }
    void OnPaint(IRenderTarget *pRT);
    void OnLButtonUp(UINT nFlags, CPoint pt);
    void Next()
    {
        if (++m_iCurState >= m_iState)
            m_iCurState = 0;
    }
    int GetNext()
    {
        int iNext = m_iCurState;
        if (++iNext >= m_iState)
            return 0;
        return iNext;
    }

    SOUI_MSG_MAP_BEGIN()
    MSG_WM_PAINT_EX(OnPaint)
    MSG_WM_LBUTTONDOWN(OnLButtonDown)
    MSG_WM_LBUTTONUP(OnLButtonUp)
    SOUI_MSG_MAP_END()
  private:
    //��ǰ��ʾ��״̬,ע��״̬��0��ʼ���
    int m_iCurState;
    //�ܹ��м���״̬
    int m_iState;
    //��ͼ��״̬���������ܹ��ж��ٸ���ͼ������ÿ��״̬�µ���ͼ��
    int m_iSkinStates;
};

SNSEND