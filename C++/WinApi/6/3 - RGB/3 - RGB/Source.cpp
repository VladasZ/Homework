#include <windows.h>
#include "resource.h"
#include <Commctrl.h>


using namespace std;



HINSTANCE hInst;


TCHAR text[50];

HWND hRed, hGreen, hBlue, hColor;

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

		hColor = GetDlgItem(hWnd, ID_COLOR);
		hRed = GetDlgItem(hWnd, SLIDE_RED);
		hGreen = GetDlgItem(hWnd, SLIDE_GREEN);
		hBlue = GetDlgItem(hWnd, SLIDE_BLUE);


		SendMessage(hRed, TBM_SETRANGE, 0, MAKELPARAM(0, 255));
		SendMessage(hGreen, TBM_SETRANGE, 0, MAKELPARAM(0, 255));
		SendMessage(hBlue, TBM_SETRANGE, 0, MAKELPARAM(0, 255));


		return TRUE;

	case WM_HSCROLL:

		

		SendMessage(hColor, PBM_SETBKCOLOR, 0, LPARAM(RGB(
			SendMessage(hRed, TBM_GETPOS, 0, 0),
			SendMessage(hGreen, TBM_GETPOS, 0, 0),
			SendMessage(hBlue, TBM_GETPOS, 0, 0)
			)));
	


		return TRUE;
	}



	return FALSE;
}