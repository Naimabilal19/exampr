#define WM_ICON WM_APP
#define ID_TRAYICON WM_USER
#include "Header.h"


HWND b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26,
b27, b28, b29,b30, edit1, edit2, progress, hDialog, radio1, radio2, radio3, hStatic;

CWaitableTimerDlg* CWaitableTimerDlg::ptr = NULL;

CWaitableTimerDlg::CWaitableTimerDlg(void)
{
	ptr = this;
	pNID = new NOTIFYICONDATA;
}

CWaitableTimerDlg::~CWaitableTimerDlg(void)
{
	delete pNID;
}

void CWaitableTimerDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL CWaitableTimerDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	b1 = GetDlgItem(hwnd, IDC_BUTTON1);
	b2 = GetDlgItem(hwnd, IDC_BUTTON2);
	b3 = GetDlgItem(hwnd, IDC_BUTTON3);
	b4 = GetDlgItem(hwnd, IDC_BUTTON4);
	b5 = GetDlgItem(hwnd, IDC_BUTTON5);
	b6 = GetDlgItem(hwnd, IDC_BUTTON6);
	b7 = GetDlgItem(hwnd, IDC_BUTTON7);
	b8 = GetDlgItem(hwnd, IDC_BUTTON8);
	b9 = GetDlgItem(hwnd, IDC_BUTTON9);
	b10 = GetDlgItem(hwnd, IDC_BUTTON10);
	b11 = GetDlgItem(hwnd, IDC_BUTTON11);
	b12 = GetDlgItem(hwnd, IDC_BUTTON12);
	b13 = GetDlgItem(hwnd, IDC_BUTTON13);
	b14 = GetDlgItem(hwnd, IDC_BUTTON14);
	b15 = GetDlgItem(hwnd, IDC_BUTTON15);
	b16 = GetDlgItem(hwnd, IDC_BUTTON16);
	b17 = GetDlgItem(hwnd, IDC_BUTTON17);
	b18 = GetDlgItem(hwnd, IDC_BUTTON18);
	b19 = GetDlgItem(hwnd, IDC_BUTTON19);
	b20 = GetDlgItem(hwnd, IDC_BUTTON20);
	b21 = GetDlgItem(hwnd, IDC_BUTTON21);
	b22 = GetDlgItem(hwnd, IDC_BUTTON22);
	b23 = GetDlgItem(hwnd, IDC_BUTTON23);
	b24 = GetDlgItem(hwnd, IDC_BUTTON24);
	b25 = GetDlgItem(hwnd, IDC_BUTTON25);
	b26 = GetDlgItem(hwnd, IDC_BUTTON26);
	b27 = GetDlgItem(hwnd, IDC_BUTTON27);
	b28 = GetDlgItem(hwnd, IDC_BUTTON28);
	b29 = GetDlgItem(hwnd, IDC_BUTTON29);
	b30 = GetDlgItem(hwnd, IDC_BUTTON30);
	edit2 = GetDlgItem(hwnd, IDC_EDIT2);
	radio1 = GetDlgItem(hwnd, IDC_RADIO1);
	radio2 = GetDlgItem(hwnd, IDC_RADIO2);
	radio3 = GetDlgItem(hwnd, IDC_RADIO3);
	hStatic = GetDlgItem(hwnd, IDC_STATIC);
	hEdit = GetDlgItem(hwnd, IDC_EDIT1);

	hDialog = hwnd;
	HINSTANCE hInst = GetModuleHandle(NULL);
	progress = GetDlgItem(hDialog, IDC_PROGRESS2);
	
	SendMessage(progress, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
	SendMessage(progress, PBM_SETSTEP, 1, 0);
	SendMessage(progress, PBM_SETPOS, 0, 0);
	SendMessage(progress, PBM_SETBKCOLOR, 0, LPARAM(RGB(0, 0, 255)));
	SendMessage(progress, PBM_SETBARCOLOR, 0, LPARAM(RGB(0, 255, 255 )));

	hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)); // загружаем иконку
	SetClassLong(hDialog, GCL_HICON, LONG(hIcon));
	memset(pNID, 0, sizeof(NOTIFYICONDATA));
	pNID->cbSize = sizeof(NOTIFYICONDATA);
	pNID->hIcon = hIcon;
	pNID->hWnd = hwnd;
	pNID->uCallbackMessage = WM_ICON;
	pNID->uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE | NIF_INFO;
	return TRUE;
}

void  CWaitableTimerDlg::Cls_OnTimer(HWND hwnd, UINT id)
{
	SendMessage(progress, PBM_STEPIT, 0, 0);
}

void CWaitableTimerDlg::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDC_BUTTON29:
	{
		MessageBox(0, TEXT("Клавиату́рный тренажёр — вид компьютерных программ, предназначенных для обучения набору на компьютерной клавиатуре. Целями тренажёров являются: увеличить скорость набора"),
			TEXT("..."), MB_OK);
		break;
	}
	case IDC_BUTTON27:
	{
		if (IDC_RADIO1)
		{
			int m = 500;
			SendMessage(progress, PBM_SETPOS, WPARAM(m), 0);
		//	SetTimer(hwnd, 1, 100, NULL);
			SetFocus(hEdit);
			break;
		}
		else if (IDC_RADIO2)
		{
			SendMessage(progress, PBM_SETPOS, 0, 0);
			int n = 200;
			SendMessage(progress, PBM_SETPOS, WPARAM(n), 0);
			//SetTimer(hwnd, 1, 100, NULL);
			
			break;
		}
		else if (IDC_RADIO3)
		{
			SendMessage(progress, PBM_STEPIT, 0, 0);
			int n = 75;
			SendMessage(progress, PBM_SETPOS, WPARAM(n), 0);
			//SetTimer(hwnd, 1, 100, NULL);
			break;
		}
		SetFocus(hEdit);
	}
	case IDC_BUTTON30:
	{
		
		MessageBox(0, TEXT("Количество ошибок:"), TEXT("_Конец_"), MB_OK);
	}
	}
}

void CWaitableTimerDlg::Cls_OnSize(HWND hwnd, UINT state, int cx, int cy)
{
	if (state == SIZE_MINIMIZED)
	{
		ShowWindow(hwnd, SW_HIDE); // Прячем окно
		Shell_NotifyIcon(NIM_ADD, pNID); // Добавляем иконку в трэй
	}
}

void CWaitableTimerDlg::OnTrayIcon(WPARAM wp, LPARAM lp)
{
	if (lp == WM_LBUTTONDBLCLK)
	{
		Shell_NotifyIcon(NIM_DELETE, pNID); 
		ShowWindow(hDialog, SW_NORMAL); 
		SetForegroundWindow(hDialog); 
	}
}

BOOL CALLBACK CWaitableTimerDlg::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hwnd, WM_SIZE, ptr->Cls_OnSize);
		HANDLE_MSG(hwnd, WM_TIMER, ptr->Cls_OnTimer);
		return TRUE;
	}
	if (message == WM_ICON)
	{
		ptr->OnTrayIcon(wParam, lParam);
		return TRUE;
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{
	INITCOMMONCONTROLSEX icc = { sizeof(INITCOMMONCONTROLSEX) };
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);
	CWaitableTimerDlg dlg;
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), NULL, CWaitableTimerDlg::DlgProc);
}

