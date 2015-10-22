#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

typedef  BOOL(*dlgPrc)(HWND, UINT, WPARAM, LPARAM);

class DllProcs
{

	dlgPrc Wm_Command, Wm_Init, Wm_Close;


public:

	bool setProc(dlgPrc Wm_Command, dlgPrc Wm_Init, dlgPrc Wm_Close);

	BOOL DllProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	DllProcs();
	DllProcs(dlgPrc Wm_Command, dlgPrc Wm_Init, dlgPrc Wm_Close);
	~DllProcs();
};

