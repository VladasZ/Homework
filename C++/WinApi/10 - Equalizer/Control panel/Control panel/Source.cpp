#include <windows.h>
#include "resource.h"



using namespace std;



HINSTANCE hInst;

TCHAR text[50];

STARTUPINFO cif;
PROCESS_INFORMATION pi;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;


	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
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

		if (wParam == IDOK) {
			ZeroMemory(&cif, sizeof(STARTUPINFO));

			CreateProcess(L"C:\\Users\\Vladas\\Desktop\\Homework\\WinApi\\10 - Equalizer\\Equalizer\\Debug\\Equalizer.exe", NULL,
				NULL, NULL, FALSE, NULL, NULL, NULL, &cif, &pi);

			return TRUE;
		}

		if(wParam == IDCANCEL)
			TerminateProcess(pi.hProcess, NO_ERROR);	// убрать процесс
		return TRUE;

	}



	return FALSE;
}