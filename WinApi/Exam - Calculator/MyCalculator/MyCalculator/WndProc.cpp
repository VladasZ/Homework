#include "WndProc.h"




bool WndProc::Wm_Command(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{

	if (wParam == BTN_AC) {// reset button
		SetWindowText(hStatusBar, L" ");
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

	HANDLE_MSG(BTN_EQ, Btn_Eq);
	HANDLE_MSG(MENU_MANUAL_INPUT, Menu_Manual);
	HANDLE_MSG(MENU_STANDART_INPUT, Menu_Standart);
	HANDLE_MSG(BTN_EVAL, Btn_Eval);

	


	return false;
}

bool WndProc::Wm_Init(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{

	hEdit = GetDlgItem(hWnd, EDIT_CONTROL);
	hResult = GetDlgItem(hWnd, EDIT_RESULT);

	

	

	hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));

	SetMenu(hWnd, hMenu);

	hStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS, 0, hWnd, WM_USER);



	CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd), 0), MENU_STANDART_INPUT, MENU_MANUAL_INPUT, MENU_STANDART_INPUT, MF_BYCOMMAND);

	GetWindowRect(hWnd, &sizeRect);

	//SetWindowLong(hWnd, GWL_STYLE, 0);

	return false;
}

bool WndProc::Btn_Eq(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	
	SetWindowText(hStatusBar, L" ");


	wcstombs(expression, edit, 50);

	try {
		swprintf(text, L"%d",
			stringParcing.calculate(expression));// sending edit expression to parser
	}

	catch (TCHAR error[]) {
		SetWindowText(hStatusBar, error);
		return TRUE;
	}

	SetWindowText(hEdit, text);

	wcscpy(edit, text);

	return false;
}

bool WndProc::Menu_Manual(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	

	CHANGE_WINDOW_BOTTOM(190);

	RARIO_CHECK(MENU_MANUAL_INPUT);

	SHOW_STANDART_ELEMS(SW_HIDE);
	SHOW_MANUAL_ELEMS(SW_SHOW);

	SendMessage(GetDlgItem(hWnd, EDIT_CONTROL), EM_SETREADONLY, 0, 0);


	hSmallStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS, 0 , hWnd, WM_USER);



	return TRUE;
}

bool WndProc::Menu_Standart(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	CHANGE_WINDOW_BOTTOM(0);

	RARIO_CHECK(MENU_STANDART_INPUT);

	SHOW_STANDART_ELEMS(SW_SHOW);
	SHOW_MANUAL_ELEMS(SW_HIDE);

	SendMessage(GetDlgItem(hWnd, EDIT_CONTROL), EM_SETREADONLY, 1, 0);

	ShowWindow(hSmallStatusBar, SW_HIDE);

	return TRUE;
}

bool WndProc::Btn_Eval(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	SetWindowText(hSmallStatusBar, L" ");

	GetWindowText(hEdit, text, 50);
	wcstombs(expression, text, 50);

	try {
		swprintf(text, L"%d",
			stringParcing.calculate(expression)// sending edit expression to parser
			);
	}

	catch (TCHAR error[]) {
		SetWindowText(hSmallStatusBar, error);
		return TRUE;
	}

	SetWindowText(hResult, text);

	return false;
}



WndProc::WndProc()
{
}
WndProc::~WndProc()
{
}
