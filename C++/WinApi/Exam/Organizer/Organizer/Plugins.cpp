#include "Plugins.h"



BOOL CALLBACK Plugins::DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	switch (message)
	{
		HANDLE_MSG(hWnd, WM_COMMAND, Wm_Command);
	}

	return 0;
}



BOOL Plugins::Wm_Command(HWND hWnd, UINT message, HWND hwndCtl, UINT codeNotify)
{



	return TRUE;
}

BOOL Plugins::Wm_InitDialog(HWND hWnd, UINT message, HWND hwndCtl, UINT codeNotify)
{

	hBtnRefresh = GetDlgItem(hWnd, PLG_BTN_REFRESH);
	hListBox = GetDlgItem(hWnd, PLG_LIST);



	return 0;
}

Plugins::Plugins()
{
}


Plugins::~Plugins()
{
}
