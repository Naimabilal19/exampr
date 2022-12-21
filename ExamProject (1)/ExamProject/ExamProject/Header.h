#pragma once
#include <windows.h>
#include <windowsX.h>
#include <ctime>
#include <tchar.h>
#include <commctrl.h>
#include "resource.h"
#include "tchar.h"
#include <string>
using std::wstring;
#pragma comment(lib,"comctl32")

class CWaitableTimerDlg
{
public:
	CWaitableTimerDlg(void);
public:
	~CWaitableTimerDlg(void);
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static CWaitableTimerDlg* ptr;
	void Cls_OnClose(HWND hwnd);
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnSize(HWND hwnd, UINT state, int cx, int cy);
	void OnTrayIcon(WPARAM wp, LPARAM lp); // обработчик пользовательского сообщени€
	void  Cls_OnTimer(HWND hwnd, UINT id);
	void KeyDown(HWND hwnd, WPARAM wParam, LPARAM lParam);
	HWND hButton, hEdit1, hSpin1, hEdit2, hSpin2, hEdit3, hSpin3, hDialog,hEdit;
	HICON hIcon;
	PNOTIFYICONDATA pNID;
};
