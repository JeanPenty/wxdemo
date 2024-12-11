//stamp:146c3aa67518a141
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#ifndef _UIRES_H_
#define _UIRES_H_
	struct _UIRES{
		struct _UIDEF{
			const TCHAR * XML_INIT;
			}UIDEF;
		struct _LAYOUT{
			const TCHAR * XML_MAINWND;
			const TCHAR * XML_PAGE_MSG;
			const TCHAR * XML_PAGE_CONTACT;
			const TCHAR * XML_PAGE_COLLECT;
			const TCHAR * XML_PAGE_FILEHELPER;
			const TCHAR * XML_PAGE_GROUPCOMM;
			const TCHAR * XML_PAGE_PERSONALCOMM;
			}LAYOUT;
		struct _values{
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
			}values;
		struct _CURSOR{
			const TCHAR * normal;
			const TCHAR * opt1;
			const TCHAR * opt2;
			const TCHAR * opt3_1;
			const TCHAR * opt3_2;
			const TCHAR * opt3_3;
			}CURSOR;
		struct _IMG{
			const TCHAR * traymenu_icons;
			}IMG;
		struct _PNG{
			const TCHAR * IDB_PNG_DEFAULTLOGO_48P;
			const TCHAR * IDB_PNG_DEFAULTLOGO_32P;
			const TCHAR * IDB_PNG_SB;
			const TCHAR * IDB_PNG_VSCROLL;
			const TCHAR * IDB_PNG_SHADOW;
			const TCHAR * IDB_PNG_GREENSHADOW;
			const TCHAR * IDB_PNG_COMMON_CLOSE;
			const TCHAR * IDB_PNG_COMMON_MIN;
			const TCHAR * IDB_PNG_COMMON_MAX;
			const TCHAR * IDB_PNG_COMMON_RESTORE;
			const TCHAR * IDB_PNG_SKIN;
			const TCHAR * IDB_PNG_MENU;
			const TCHAR * IDB_PNG_MESSAGE;
			const TCHAR * IDB_PNG_CONTACT;
			const TCHAR * IDB_PNG_FAVORITES;
			const TCHAR * IDB_PNG_SEARCH;
			const TCHAR * IDB_PNG_SEARCHCANCEL;
			const TCHAR * IDB_PNG_DEFAULTPERSONAL32;
			const TCHAR * IDB_PNG_EMOTION;
			const TCHAR * IDB_PNG_IMAGE;
			const TCHAR * IDB_PNG_FILE;
			const TCHAR * IDB_PNG_SNAPSHOT;
			const TCHAR * IDB_PNG_SNAPSHOT_ARROW;
			const TCHAR * IDB_PNG_HISTORY;
			const TCHAR * IDB_PNG_SEND;
			}PNG;
		struct _ICON{
			const TCHAR * ICON_LOGO;
			}ICON;
		struct _translator{
			const TCHAR * lang_cn;
			const TCHAR * lang_jp;
			}translator;
		struct _SMENU{
			const TCHAR * menu_tray;
			}SMENU;
	};
#endif//_UIRES_H_
#ifdef INIT_R_DATA
struct _UIRES UIRES={
		{
			_T("UIDEF:XML_INIT"),
		},
		{
			_T("LAYOUT:XML_MAINWND"),
			_T("LAYOUT:XML_PAGE_MSG"),
			_T("LAYOUT:XML_PAGE_CONTACT"),
			_T("LAYOUT:XML_PAGE_COLLECT"),
			_T("LAYOUT:XML_PAGE_FILEHELPER"),
			_T("LAYOUT:XML_PAGE_GROUPCOMM"),
			_T("LAYOUT:XML_PAGE_PERSONALCOMM"),
		},
		{
			_T("values:string"),
			_T("values:color"),
			_T("values:skin"),
		},
		{
			_T("CURSOR:normal"),
			_T("CURSOR:opt1"),
			_T("CURSOR:opt2"),
			_T("CURSOR:opt3_1"),
			_T("CURSOR:opt3_2"),
			_T("CURSOR:opt3_3"),
		},
		{
			_T("IMG:traymenu_icons"),
		},
		{
			_T("PNG:IDB_PNG_DEFAULTLOGO_48P"),
			_T("PNG:IDB_PNG_DEFAULTLOGO_32P"),
			_T("PNG:IDB_PNG_SB"),
			_T("PNG:IDB_PNG_VSCROLL"),
			_T("PNG:IDB_PNG_SHADOW"),
			_T("PNG:IDB_PNG_GREENSHADOW"),
			_T("PNG:IDB_PNG_COMMON_CLOSE"),
			_T("PNG:IDB_PNG_COMMON_MIN"),
			_T("PNG:IDB_PNG_COMMON_MAX"),
			_T("PNG:IDB_PNG_COMMON_RESTORE"),
			_T("PNG:IDB_PNG_SKIN"),
			_T("PNG:IDB_PNG_MENU"),
			_T("PNG:IDB_PNG_MESSAGE"),
			_T("PNG:IDB_PNG_CONTACT"),
			_T("PNG:IDB_PNG_FAVORITES"),
			_T("PNG:IDB_PNG_SEARCH"),
			_T("PNG:IDB_PNG_SEARCHCANCEL"),
			_T("PNG:IDB_PNG_DEFAULTPERSONAL32"),
			_T("PNG:IDB_PNG_EMOTION"),
			_T("PNG:IDB_PNG_IMAGE"),
			_T("PNG:IDB_PNG_FILE"),
			_T("PNG:IDB_PNG_SNAPSHOT"),
			_T("PNG:IDB_PNG_SNAPSHOT_ARROW"),
			_T("PNG:IDB_PNG_HISTORY"),
			_T("PNG:IDB_PNG_SEND"),
		},
		{
			_T("ICON:ICON_LOGO"),
		},
		{
			_T("translator:lang_cn"),
			_T("translator:lang_jp"),
		},
		{
			_T("SMENU:menu_tray"),
		},
	};
#else
extern struct _UIRES UIRES;
#endif//INIT_R_DATA

#ifndef _R_H_
#define _R_H_
struct _R{
	struct _name{
		 const wchar_t * btn_close;
		 const wchar_t * btn_contact;
		 const wchar_t * btn_emotion;
		 const wchar_t * btn_favorites;
		 const wchar_t * btn_file;
		 const wchar_t * btn_history;
		 const wchar_t * btn_image;
		 const wchar_t * btn_max;
		 const wchar_t * btn_menu;
		 const wchar_t * btn_message;
		 const wchar_t * btn_min;
		 const wchar_t * btn_msg_search_cancel;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_send;
		 const wchar_t * btn_skin;
		 const wchar_t * btn_snapshot;
		 const wchar_t * btn_snapshot_arrow;
		 const wchar_t * edit_msg_search;
		 const wchar_t * edit_recv;
		 const wchar_t * edit_send;
		 const wchar_t * item_avatar;
		 const wchar_t * item_content;
		 const wchar_t * item_name;
		 const wchar_t * item_reminder;
		 const wchar_t * item_time;
		 const wchar_t * lv_message;
		 const wchar_t * main_logo;
		 const wchar_t * tab_main_opt;
		 const wchar_t * tab_msg_comm;
		 const wchar_t * text_talk_title;
	}name;
	struct _id{
		int btn_close;
		int btn_contact;
		int btn_emotion;
		int btn_favorites;
		int btn_file;
		int btn_history;
		int btn_image;
		int btn_max;
		int btn_menu;
		int btn_message;
		int btn_min;
		int btn_msg_search_cancel;
		int btn_restore;
		int btn_send;
		int btn_skin;
		int btn_snapshot;
		int btn_snapshot_arrow;
		int edit_msg_search;
		int edit_recv;
		int edit_send;
		int item_avatar;
		int item_content;
		int item_name;
		int item_reminder;
		int item_time;
		int lv_message;
		int main_logo;
		int tab_main_opt;
		int tab_msg_comm;
		int text_talk_title;
	}id;
	struct _color{
		int blue;
		int gray;
		int green;
		int red;
		int white;
	}color;
	struct _string{
		int title;
		int ver;
	}string;

};
#endif//_R_H_
#ifdef INIT_R_DATA
struct _R R={
	{
		L"btn_close",
		L"btn_contact",
		L"btn_emotion",
		L"btn_favorites",
		L"btn_file",
		L"btn_history",
		L"btn_image",
		L"btn_max",
		L"btn_menu",
		L"btn_message",
		L"btn_min",
		L"btn_msg_search_cancel",
		L"btn_restore",
		L"btn_send",
		L"btn_skin",
		L"btn_snapshot",
		L"btn_snapshot_arrow",
		L"edit_msg_search",
		L"edit_recv",
		L"edit_send",
		L"item_avatar",
		L"item_content",
		L"item_name",
		L"item_reminder",
		L"item_time",
		L"lv_message",
		L"main_logo",
		L"tab_main_opt",
		L"tab_msg_comm",
		L"text_talk_title"
	}
	,
	{
		65541,
		65538,
		65558,
		65539,
		65560,
		65563,
		65559,
		65542,
		65545,
		65537,
		65544,
		65548,
		65543,
		65565,
		65546,
		65561,
		65562,
		65547,
		65557,
		65564,
		65550,
		65552,
		65551,
		65554,
		65553,
		65549,
		65536,
		65540,
		65556,
		65555
	}
	,
	{
		0,
		1,
		2,
		3,
		4
	}
	,
	{
		0,
		1
	}
	
};
#else
extern struct _R R;
#endif//INIT_R_DATA
