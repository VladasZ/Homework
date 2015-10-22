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