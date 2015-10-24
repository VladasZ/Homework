#include "WndProc.h"




bool WndProc::Wm_Command(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{

	wsprintf(text, L"%d", wParam);
	SetWindowText(hWnd, text);

	if (wParam == BTN_AC) {// reset button
		edit[0] = L'\0';
		SetWindowText(hEdit, edit);
		return TRUE;
	}

	if (wParam == BTN_BACKSPACE) {// backspace button
		if (!wcslen(edit)) return TRUE;
		edit[wcslen(edit) - 1] = L'\0';
		SetWindowText(hEdit, edit);
		return TRUE;
	}

	if (wParam == BTN_LEFT_BRACKET || wParam == BTN_RIGHT_BRACKET) {// showing brackets

		GetWindowText(GetDlgItem(hWnd, wParam), text, 50);
		wcscat_s(edit, text);
		SetWindowText(hEdit, edit);

		return TRUE;
	}

	if (wParam >= IDC_BUTTON1 && wParam <= IDC_BUTTON10) { // showing digits
		wsprintf(text, TEXT("%d"), wParam % 10);
		wcscat_s(edit, text);
		SetWindowText(hEdit, edit);

		return TRUE;
	}


	if (wParam == BTN_SUB && !wcslen(edit)) { //  allowing minus as first character
		wsprintf(text, TEXT("-"));
		wcscat_s(edit, text);
		SetWindowText(hEdit, edit);
		return TRUE;
	}


	if (wParam >= BTN_DIV && wParam <= BTN_PLUS) {

		if (edit[wcslen(edit) - 1] != '(' && edit[wcslen(edit) - 1] != ')') { //excluding brackets from check

			if (edit[wcslen(edit) - 1] < L'0' ||  // preventing double symbols 
				edit[wcslen(edit) - 1] > L'9' ||
				!wcslen(edit))					  // and first character as symbol
				return TRUE;					  // minus is allowed as first character if prev i
		}

		GetWindowText(
			GetDlgItem(hWnd, wParam),
			text, 50);


		wcscat_s(edit, text);
		SetWindowText(hEdit, edit);


	}

	

	HANDLE_MSG(MENU_MANUAL_INPUT, Menu_Manual);

	HANDLE_MSG(MENU_STANDART_INPUT, Menu_Standart);

	HANDLE_MSG(BTN_EQ, Btn_Eq);
	


	return false;
}

bool WndProc::Wm_Init(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{

	hEdit = GetDlgItem(hWnd, EDIT_CONTROL);

	hLib = LoadLibrary(L"Check Brackets DLL.dll");

	checkBrackets = (dllFunc)GetProcAddress((HMODULE)hLib, "checkBrackets");

	hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));

	SetMenu(hWnd, hMenu);

	hStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS, 0, hWnd, WM_USER);


	CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd), 0), MENU_STANDART_INPUT, MENU_MANUAL_INPUT, MENU_STANDART_INPUT, MF_BYCOMMAND);

	GetWindowRect(hWnd, &rect);

	//SetWindowLong(hWnd, GWL_STYLE, 0);

	return false;
}

bool WndProc::Btn_Eq(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (!wcslen(edit)) return TRUE;


	if ((edit[wcslen(edit) - 1] < L'0' || edit[wcslen(edit) - 1] > L'9') &&
		edit[wcslen(edit) - 1] != '(' && edit[wcslen(edit) - 1] != ')') {
		SetWindowText(hStatusBar, L"Enter last value");
		return TRUE;
	}

	if (!checkBrackets(edit)) {
		SetWindowText(hStatusBar, L"Check brackets");
		//MessageBox(hWnd, L"Check brackets", L"Error", MB_OK);
		return TRUE;
	}
	SetWindowText(hStatusBar, L" ");


	wcstombs(expression, edit, 50);


	swprintf(text, L"%d",
		stringParcing.calculate(expression)// sending edit expression to parser
		);

	SetWindowText(hEdit, text);

	wcscpy(edit, text);

	return false;
}

bool WndProc::Menu_Manual(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
		
	CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd), 0), MENU_STANDART_INPUT, MENU_MANUAL_INPUT, MENU_MANUAL_INPUT, MF_BYCOMMAND);



	MoveWindow(hWnd, 0, 0 , rect.right, rect.bottom - 200, 1);

	ShowWindow(GetDlgItem(hWnd,BTN_AC), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, BTN_BACKSPACE), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, BTN_LEFT_BRACKET), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, BTN_RIGHT_BRACKET), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, IDC_BUTTON7), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, IDC_BUTTON8), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, IDC_BUTTON9), SW_HIDE);
	ShowWindow(GetDlgItem(hWnd, BTN_DIV), SW_HIDE);


	return false;
}

bool WndProc::Menu_Standart(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd), 0), MENU_STANDART_INPUT, MENU_MANUAL_INPUT, MENU_STANDART_INPUT, MF_BYCOMMAND);



	MoveWindow(hWnd, 0, 0, rect.right, rect.bottom, 1);

	ShowWindow(GetDlgItem(hWnd, BTN_AC), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, BTN_BACKSPACE), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, BTN_LEFT_BRACKET), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, BTN_RIGHT_BRACKET), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, IDC_BUTTON7), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, IDC_BUTTON8), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, IDC_BUTTON9), SW_SHOW);
	ShowWindow(GetDlgItem(hWnd, BTN_DIV), SW_SHOW);

	return false;
}



WndProc::WndProc()
{
}
WndProc::~WndProc()
{
}
