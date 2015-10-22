#include <windows.h>
#include "resource.h"
#include "DllProcs.h"
#include <vector>
#include<memory>

#define IDD_MAINDLG 547



using namespace std;


HINSTANCE hInst;

HANDLE hLib;
HRSRC hResInfo;
HGLOBAL hGblRes;

typedef shared_ptr<DllProcs> LPDllProcs;
#define NEW_DLLPROC make_shared<DllProcs>

vector<LPDllProcs> dllProcs;

DllProcs myDllProc;

TCHAR text[50];

BOOL  DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);





int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;

	return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgProc);
}




BOOL DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;



	case WM_INITDIALOG:



		return TRUE;

	case WM_COMMAND:

		if (wParam == MAIN_BTN_PLUGINS) {


			hLib = LoadLibrary(L"Plugins\\Task list.dll");

			/*dllProcs.push_back(
				NEW_DLLPROC(
					(dlgPrc)GetProcAddress((HMODULE)hLib, "Wm_Init"),
					(dlgPrc)GetProcAddress((HMODULE)hLib, "Wm_Command"),
					(dlgPrc)GetProcAddress((HMODULE)hLib, "Wm_Close")
					)
				);*/

			myDllProc.setProc(
				(dlgPrc)GetProcAddress((HMODULE)hLib, "Wm_Init"),
				(dlgPrc)GetProcAddress((HMODULE)hLib, "Wm_Command"),
				(dlgPrc)GetProcAddress((HMODULE)hLib, "Wm_Close")
				);
			
		

			hResInfo = FindResource((HMODULE)hLib, MAKEINTRESOURCE(101), RT_DIALOG);
			hGblRes = LoadResource((HMODULE)hLib, hResInfo);

			CreateDialogIndirect(hInst, (LPCDLGTEMPLATE)hGblRes, hWnd, myDllProc.DllProc);

		}

		return TRUE;
	}



	return FALSE;
}

