#include <windows.h>
#include "resource.h"
#include <vector>
#include <memory>




using namespace std;


HINSTANCE hInst;

HANDLE hLib;
HRSRC hResInfo;
HGLOBAL hGblRes;





typedef  BOOL(CALLBACK *dlgPrc)(HWND, UINT, WPARAM, LPARAM);

dlgPrc dllProc;

TCHAR text[50];

BOOL CALLBACK  DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);





int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;

	return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgProc);
}




BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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


			hLib = LoadLibrary(L"C:\\Users\\Vladas\\Desktop\\Homework\\WinApi\\Exam\\Task list\\Debug\\Task list.dll");

			


			dllProc = (dlgPrc)GetProcAddress((HMODULE)hLib, "DlgProc");

			if (!(dlgPrc)GetProcAddress((HMODULE)hLib, "DlgProc")) {
				MessageBox(hWnd, L"bla bla", L"you mda", MB_OK);
			}
			hResInfo = FindResource((HMODULE)hLib, MAKEINTRESOURCE(101), RT_DIALOG);
			hGblRes = LoadResource((HMODULE)hLib, hResInfo);

			CreateDialogIndirect(hInst, (LPCDLGTEMPLATE)hGblRes, hWnd, (DLGPROC)(dllProc));

		}

		return TRUE;
	}



	return FALSE;
}

