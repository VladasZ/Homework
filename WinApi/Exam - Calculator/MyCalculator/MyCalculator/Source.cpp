#include <Windows.h>
#include "resource.h"
#include <string>
#include "StringParsing.h"

using namespace std;

HINSTANCE hInst;
HINSTANCE hLib;
HWND hEdit;

typedef bool(*dllFunc)(const TCHAR[]);

dllFunc checkBrackets;

BOOL CALLBACK DlgProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

TCHAR text[50];
TCHAR edit[50];



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){
	hInst = hInstance;

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam){

	switch (Message)
	{

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;


	case WM_INITDIALOG:
		hEdit = GetDlgItem(hWnd, EDIT_CONTROL);

		hLib = LoadLibrary(L"Check Brackets DLL.dll");
		
		checkBrackets = (dllFunc)GetProcAddress((HMODULE)hLib, "checkBrackets");

		return TRUE;



	case WM_COMMAND:


		
		

		if (wParam >= IDC_BUTTON1 && wParam <= IDC_BUTTON10){ // showing digits
			wsprintf(text, TEXT("%d"), wParam % 10);
			wcscat_s(edit, text);
			SetWindowText(hEdit, edit);

			return TRUE;
		}


		if (wParam == BTN_SUB && !wcslen(edit)){ //  allowing minus as first character
			wsprintf(text, TEXT("-"));
			wcscat_s(edit, text);
			SetWindowText(hEdit, edit);
			return TRUE;
		}


		if (wParam >= BTN_DIV && wParam <= BTN_PLUS){
		
			if (edit[wcslen(edit)- 1] < L'0'  ||  // preventing double symbols 
				edit[wcslen(edit) - 1] > L'9' ||
				!wcslen(edit))					  // and first character as symbol
				return TRUE;					  // minus is allowed as first character if prev if


				GetWindowText(
				GetDlgItem(hWnd, wParam),
				text, 50);

				

				wcscat_s(edit, text);
				SetWindowText(hEdit, edit);
		}

		if (wParam == BTN_EQ){

			GetWindowText(
				hEdit,
				text, 50);

			if (checkBrackets(text))
				return TRUE;

			MessageBox(hWnd, L"Check brackets", L"Error", MB_OK);
			return TRUE;


		}

		

		break;



	default:
		break;
	}



	return FALSE;

}


