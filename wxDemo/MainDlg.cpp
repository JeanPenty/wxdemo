// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
#include <helper/SMenuEx.h>

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
}

CMainDlg::~CMainDlg()
{
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	CGlobalUnits::instance()->m_strTest = "1111111";

	STabCtrl* pMainOptTab = FindChildByName2<STabCtrl>(L"tab_main_opt");
	IWindow* pPageMessage = pMainOptTab->GetPage(0);
	IWindow* pPageContact = pMainOptTab->GetPage(1);
	IWindow* pPageCollect = pMainOptTab->GetPage(2);

	SImageButton* pBtnMessage = FindChildByName2<SImageButton>(L"btn_message");
	SImageButton* pBtnContact = FindChildByName2<SImageButton>(L"btn_contact");
	SImageButton* pBtnCollect = FindChildByName2<SImageButton>(L"btn_favorites");

	pBtnMessage->SetCheck(TRUE);
	pBtnContact->SetCheck(FALSE);
	pBtnCollect->SetCheck(FALSE);

	SListView* pLvMessage = FindChildByName2<SListView>(L"lv_message");
	pLvMessage->EnableScrollBar(SSB_HORZ, FALSE);

	m_pMessageAdapter = new CLvMessageAdapter(pLvMessage, this);
	pLvMessage->SetAdapter(m_pMessageAdapter);
	m_pMessageAdapter->Release();

	STabCtrl* pTabMessageComm = (STabCtrl*)pPageMessage->FindIChildByName(L"tab_msg_comm");
	SASSERT(pTabMessageComm);
	for (int i = 0; i < 10; i++)
	{
		SStringW sstrID;
		sstrID.Format(L"%d", i);

		SStringW sstrPage;
		sstrPage.Format(L"<page title='%s'><include src='layout:XML_PAGE_PERSONALCOMM'/></page>", sstrID);
		pTabMessageComm->InsertItem(sstrPage);

		SStringW sstrAvatar = L"";
		SStringW sstrName;
		sstrName.Format(L"个人测试%d", i);
		SStringW sstrContent = L"测试1231241231231231123124123123123123122312";
		SStringW sstrTime = L"2024-12-22";
		bool bReminder = false;

		int nType = 1;
		m_pMessageAdapter->AddItem(sstrID, nType, sstrAvatar, sstrName, sstrContent, sstrTime, bReminder);
	}

	return 0;
}

void CMainDlg::OnLanguageBtnCN()
{
	OnLanguage(1);
}
void CMainDlg::OnLanguageBtnJP()
{
	OnLanguage(0);
}
void CMainDlg::OnLanguage(int nID)
{
	ITranslatorMgr *pTransMgr = SApplication::getSingletonPtr()->GetTranslator();
	SASSERT(pTransMgr);
	bool bCnLang = nID == 1;

	SXmlDoc xmlLang;
	if (SApplication::getSingletonPtr()->LoadXmlDocment(xmlLang, bCnLang ? _T("translator:lang_cn") : _T("translator:lang_jp")))
	{
		CAutoRefPtr<ITranslator> lang;
		pTransMgr->CreateTranslator(&lang);
		lang->Load(&xmlLang.root().child(L"language"), 1);//1=LD_XML
		TCHAR lngName[TR_MAX_NAME_LEN] = {0};
		lang->GetName(lngName);
        pTransMgr->SetLanguage(lngName);
		pTransMgr->InstallTranslator(lang);
        GetRoot()->SDispatchMessage(UM_SETLANGUAGE, 0, 0);
	}
}

//TODO:消息映射
void CMainDlg::OnClose()
{
	SNativeWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}


//演示如何响应菜单事件
void CMainDlg::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl)
{
	if (uNotifyCode == 0)
	{
		switch (nID)
		{
		case 6:
			PostMessage(WM_CLOSE);
			break;
		default:
			break;
		}
	}
}


void CMainDlg::OnShellTrayNotify(IEvtArgs * e)
{
	EventTrayNotify *e2 = sobj_cast<EventTrayNotify>(e);
	SShellTray *pTray = sobj_cast<SShellTray>(e->Sender());
	switch(e2->lp)
	{
	case WM_LBUTTONDOWN:
		if(IsWindowVisible())
		{
			ShowWindow(SW_HIDE);
		}else
		{
			ShowWindow(SW_SHOW);
			if(IsIconic())
			{
				OnRestore();
			}
		}
		break;
	case WM_RBUTTONDOWN:
		{
			SMenu menu;
			if (menu.LoadMenu(_T("SMENU:menu_tray")))
			{
				POINT pt;
				GetCursorPos(&pt);
				SetForegroundWindow(m_hWnd);
				menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);
			}
		}
		break;
	}
}


void CMainDlg::OnBnClickMessage()
{
	STabCtrl* pMainOptTab = FindChildByName2<STabCtrl>(L"tab_main_opt");

	SImageButton* pBtnMessage = FindChildByName2<SImageButton>(L"btn_message");
	SImageButton* pBtnContact = FindChildByName2<SImageButton>(L"btn_contact");
	SImageButton* pBtnCollect = FindChildByName2<SImageButton>(L"btn_favorites");

	pBtnMessage->SetCheck(TRUE);
	pBtnContact->SetCheck(FALSE);
	pBtnCollect->SetCheck(FALSE);

	pMainOptTab->SetCurSel(0);
}

void CMainDlg::OnBnClickContact()
{
	STabCtrl* pMainOptTab = FindChildByName2<STabCtrl>(L"tab_main_opt");

	SImageButton* pBtnMessage = FindChildByName2<SImageButton>(L"btn_message");
	SImageButton* pBtnContact = FindChildByName2<SImageButton>(L"btn_contact");
	SImageButton* pBtnCollect = FindChildByName2<SImageButton>(L"btn_favorites");

	pBtnMessage->SetCheck(FALSE);
	pBtnContact->SetCheck(TRUE);
	pBtnCollect->SetCheck(FALSE);

	pMainOptTab->SetCurSel(1);
}

void CMainDlg::OnBnClickCollect()
{
	STabCtrl* pMainOptTab = FindChildByName2<STabCtrl>(L"tab_main_opt");

	SImageButton* pBtnMessage = FindChildByName2<SImageButton>(L"btn_message");
	SImageButton* pBtnContact = FindChildByName2<SImageButton>(L"btn_contact");
	SImageButton* pBtnCollect = FindChildByName2<SImageButton>(L"btn_favorites");

	pBtnMessage->SetCheck(FALSE);
	pBtnContact->SetCheck(FALSE);
	pBtnCollect->SetCheck(TRUE);

	pMainOptTab->SetCurSel(2);
}

bool CMainDlg::OnEditMessageSearchSetFocus(EventArgs* pEvt)
{
	//展示搜索框中的取消搜索按钮
	SImageButton* pSearchCancel = FindChildByName2<SImageButton>(L"btn_msg_search_cancel");
	pSearchCancel->SetAttribute(L"show", L"1");

	//需要展示搜索页面
	//TODO:
	return true;
}

bool CMainDlg::OnEditMessageSearchKillFocus(EventArgs* pEvt)
{
	SImageButton* pSearchCancel = FindChildByName2<SImageButton>(L"btn_msg_search_cancel");
	pSearchCancel->SetAttribute(L"show", L"0");

	//重新展示消息列表
	return true;
}

bool CMainDlg::OnEditMessageSearchChanged(EventArgs* e)
{
	return true;
}

void CMainDlg::OnMessageItemClick(int& nIndex)
{
	//
	STabCtrl* pMainOptTab = FindChildByName2<STabCtrl>(L"tab_main_opt");
	IWindow* pPageMessage = pMainOptTab->GetPage(0);
	STabCtrl* pTabMessageComm = (STabCtrl*)pPageMessage->FindIChildByName(L"tab_msg_comm");
	SASSERT(pTabMessageComm);

	pTabMessageComm->SetCurSel(nIndex);

	SStatic* pTitle = (SStatic*)pPageMessage->FindIChildByName(L"text_talk_title");
	CLvMessageAdapter::ItemData* pData = m_pMessageAdapter->GetItemData(nIndex);
	if (pData)
	{
		pTitle->SetWindowTextW(pData->m_sstrName);
	}
}