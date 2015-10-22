#include "DllProcs.h"

bool DllProcs::setProc(dlgPrc Wm_Command, dlgPrc Wm_Init, dlgPrc Wm_Close)
{

	this->Wm_Close = Wm_Close;
	this->Wm_Command = Wm_Command;
	this->Wm_Init = Wm_Init;


	return false;
}

BOOL DllProcs::DllProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message)
	{
	case WM_CLOSE:
		Wm_Close(hWnd, message, wParam, lParam);
		return TRUE;


	case WM_INITDIALOG:
		Wm_Init(hWnd, message, wParam, lParam);
		return TRUE;

	case WM_COMMAND:

		Wm_Command(hWnd, message, wParam, lParam);

		return true;

	}

	return false;
}

DllProcs::DllProcs()
{
}

DllProcs::DllProcs(dlgPrc Wm_Command, dlgPrc Wm_Init, dlgPrc Wm_Close)
	:
	Wm_Command(Wm_Command),
	Wm_Init(Wm_Init),
	Wm_Close(Wm_Close)
{
}


DllProcs::~DllProcs()
{
}
