#include <windows.h>
#include "resource.h"
#include "TaskManager.h"



using namespace std;



HINSTANCE hInst;

TCHAR text[50];

TaskManager taskManager;

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
		taskManager.init(hWnd, message, wParam, lParam);
		return TRUE;

	case WM_COMMAND:
		taskManager.wmCommand(hWnd, message, wParam, lParam);
		return TRUE;


	case WM_LBUTTONDBLCLK:
		taskManager.dblClick(hWnd, message, wParam, lParam);
		return TRUE;


	}



	return FALSE;
}