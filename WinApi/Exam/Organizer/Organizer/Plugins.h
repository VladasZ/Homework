#include <Windows.h>
#include <windowsx.h>
#include "resource.h"


#pragma once
class Plugins
{

	HWND hListBox, hBtnRefresh;
public:

	BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	BOOL Wm_Command(HWND hWnd, UINT message, HWND hwndCtl, UINT codeNotify);
	BOOL Wm_InitDialog(HWND hWnd, UINT message, HWND hwndCtl, UINT codeNotify);

	Plugins();
	~Plugins();
};

