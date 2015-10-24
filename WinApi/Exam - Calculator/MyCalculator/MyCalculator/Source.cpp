#include <Windows.h>
#include "resource.h"
#include "StringParsing.h"
#include <commctrl.h>


#pragma comment(lib,"comctl32")

using namespace std;

HINSTANCE hInst;
HINSTANCE hLib;
HWND hEdit, hStatusBar;

HMENU hMenu;

StringParsing stringParcing;

typedef bool(*dllFunc)(const TCHAR[]);

dllFunc checkBrackets;

BOOL CALLBACK DlgProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

TCHAR text[50];
TCHAR edit[50];
char expression[50];


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	hInst = hInstance;

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {

	switch (Message)
	{

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;


	case WM_INITDIALOG:
		hEdit = GetDlgItem(hWnd, EDIT_CONTROL);

		hLib = LoadLibrary(L"Check Brackets DLL.dll");

		checkBrackets = (dllFunc)GetProcAddress((HMODULE)hLib, "checkBrackets");

		hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));

		SetMenu(hWnd, hMenu);

		hStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS, 0, hWnd, WM_USER);

		
		CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd), 1), ID_DIALOG_SHOW,
			ID_DIALOG_HIDE, ID_DIALOG_SHOW, MF_BYCOMMAND);
		

		//SetWindowLong(hWnd, GWL_STYLE, 0);

		return TRUE;



	case WM_COMMAND:


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

		if (wParam == BTN_EQ) {

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


			return TRUE;

		}


		break;

	default:
		break;
	}



	return FALSE;

}


