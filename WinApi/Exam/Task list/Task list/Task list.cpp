// Task list.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

//typedef BOOL(*dlgPrc)(HWND, UINT, WPARAM, LPARAM);

extern "C" __declspec(dllexport) bool isComparable() {
	return true;
}



extern "C" __declspec(dllexport) bool Wm_Init(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	MessageBox(hWnd, L"bla bla", L"init dlg", MB_OK);
	return true;
}

extern "C" __declspec(dllexport) bool Wm_Command(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (wParam == BTN_ADD) {
		MessageBox(hWnd, L"bla bla", L"add", MB_OK);
	}
	return true;
}

extern "C" __declspec(dllexport) bool Wm_Close(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	EndDialog(hWnd, 0);
	return true;
}


extern "C" __declspec(dllexport) bool DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;



	case WM_INITDIALOG:



		return TRUE;

	case WM_COMMAND:

		if (wParam == BTN_ADD) {

			MessageBox(hWnd, L"bla bla", L"adddddd", MB_OK);
		}

		if (wParam == IDCANCEL) {
			EndDialog(hWnd, 0);
		}

		if (wParam == IDOK) {
			static HWND list = GetDlgItem(hWnd, IDC_LIST1);
			SendMessage(list, LB_ADDSTRING, 0, (WPARAM)L"FDFDF");
		}

		return TRUE;
	}



	return FALSE;
}

