#pragma once

#include "slistboxex.h"
SNSBEGIN

DEF_EVT_EXT(EventOfComoboxExItem,EVT_EXTERNAL_BEGIN + 300,{
	EventCmd *pOrgEvt;
	BOOL bCancel;
});


class SComboBoxEx : public SComboBase {
    DEF_SOBJECT(SComboBase, L"comboboxex")
  public:
    /**
     * SComboBoxEx::SComboBoxEx
     * @brief    ���캯��
     *
     * Describe  ���캯��
     */
    SComboBoxEx();
    /**
     * SComboBoxEx::~SComboBoxEx
     * @brief    ��������
     *
     * Describe  ��������
     */
    virtual ~SComboBoxEx();

    /**
     * SComboBoxEx::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    BOOL WINAPI SetCurSel(int iSel) override
    {
        if (m_pListBox->SetCurSel(iSel))
        {
            OnSelChanged();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    /**
     * SComboBoxEx::GetCurSel
     * @brief    ��ȡѡ������
     * @return   ����int -- ѡ������
     *
     * Describe  ��ȡѡ������
     */
    int WINAPI GetCurSel() const override
    {
        return m_pListBox->GetCurSel();
    }

    /**
     * SComboBox::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    int WINAPI GetCount() const override
    {
        return m_pListBox->GetItemCount();
    }

    /**
     * SComboBoxEx::GetItemData
     * @brief    ��ȡ��������
     * @param    UINT iItem -- ѡ��ֵ
     *
     * Describe  ��ȡ��������
     */
    LPARAM GetItemData(UINT iItem) const
    {
        return m_pListBox->GetItemData(iItem);
    }

    /**
     * SComboBoxEx::SetItemData
     * @brief    ���ø�������
     * @param    UINT iItem -- ����ֵ
     * @param    LPARAM lParam -- ����ֵ
     *
     * Describe  ���ø�������
     */
    void SetItemData(UINT iItem, LPARAM lParam)
    {
        m_pListBox->SetItemData(iItem, lParam);
    }

    /**
     * SComboBoxEx::InsertItem
     * @brief    ��������
     * @param    UINT iPos -- λ��
     * @param    LPCTSTR pszText -- �ı�ֵ
     * @param    int iIcon -- ͼ��
     * @param    LPARAM lParam -- ����ֵ
     *
     * Describe  ��������
     */

    int InsertItem(UINT iPos, LPCTSTR pszText, int iIcon, LPARAM lParam)
    {
        int iInserted = m_pListBox->InsertItem(iPos, NULL, lParam);
        if (iInserted != -1)
        {
            SWindow *pWnd = m_pListBox->GetItemPanel(iInserted);
            if (m_uTxtID != 0)
            {
                SWindow *pText = pWnd->FindChildByID(m_uTxtID);
                if (pText)
                    pText->SetWindowText(pszText);
            }
            if (m_uIconID != 0)
            {
                SImageWnd *pIcon = pWnd->FindChildByID2<SImageWnd>(m_uIconID);
                if (pIcon)
                    pIcon->SetIcon(iIcon);
            }
        }
        return iInserted;
    }
    /**
     * SComboBoxEx::DeleteString
     * @brief    ɾ��ĳһ��
     * @param    UINT iItem -- ����ֵ
     *
     * Describe  ɾ��ĳһ��
     */
    void DeleteString(UINT iItem)
    {
        m_pListBox->DeleteItem(iItem);
    }

    /**
     * SComboBoxEx::ResetContent
     * @brief    ɾ��������
     *
     * Describe  ���ø�������
     */
    void ResetContent()
    {
        return m_pListBox->DeleteAllItems();
    }

    /**
     * SComboBoxEx::GetLBText
     * @brief    ��ȡ�ı�
     * @param    int iItem -- ����ֵ
     *
     * Describe  ��ȡ�ı�
     */
    SStringT GetLBText(int iItem);

    SListBoxEx *GetListBox()
    {
        return m_pListBox;
    }

  protected:
    /**
     * SComboBox::OnSelChanged
     * @brief    �����б�selected�¼�
     *
     * Describe  �����б�selected�¼�
     */
    virtual void OnSelChanged();

  protected:
    /**
     * SComboBoxEx::FireEvent
     * @brief    ֪ͨ��Ϣ
     * @param    IEvtArgs &evt -- �¼�����
     *
     * Describe  �˺�������Ϣ��Ӧ����
     */
    BOOL WINAPI FireEvent(IEvtArgs *evt) override;

    /**
     * SComboBoxEx::CreateListBox
     * @brief    ���������б�
     * @param    ����BOOL TRUE -- �ɹ� FALSE -- ʧ��
     *
     * Describe  ���������б�
     */
    BOOL CreateListBox(SXmlNode xmlNode) override;

    /**
     * SComboBoxEx::GetListBoxHeight
     * @brief    ��ȡ�����б�߶�
     * @param    ����int
     *
     * Describe  ��ȡ�����б�߶�
     */
    int GetListBoxHeight() override;

    /**
     * SComboBoxEx::OnDropDown
     * @brief    �����б��¼�
     * @param    SDropDownWnd *pDropDown -- �����б�ָ��
     *
     * Describe  �����б��¼�
     */
    virtual void OnCreateDropDown(SDropDownWnd *pDropDown);

    /**
     * SComboBox::OnCloseUp
     * @brief    �����б�ر��¼�
     * @param    SDropDownWnd *pDropDown -- �����б�ָ��
     *
     * Describe  ��ȡ�����б�ָ��
     */
    virtual void OnDestroyDropDown(SDropDownWnd *pDropDown);

  protected:
    SOUI_ATTRS_BEGIN()
    ATTR_UINT(L"id_text", m_uTxtID, FALSE)
    ATTR_UINT(L"id_icon", m_uIconID, FALSE)
    SOUI_ATTRS_END()

    SListBoxEx *m_pListBox; /**< SListBoxָ�� */
    UINT m_uTxtID;          /**< �ı�ID */
    UINT m_uIconID;         /**< ͼ��ID */
};

SNSEND