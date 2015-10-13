#include <windows.h>
#include "resource.h"



using namespace std;



HINSTANCE hInst;
HWND hList, hAdd, hMult, hMean, hDisplay, hButton;


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

		hList = GetDlgItem(hWnd, LIST1);
		hAdd = GetDlgItem(hWnd, RADIO_ADDITION);
		hMult = GetDlgItem(hWnd, RADIO_MULTIPLICATION);
		hMean = GetDlgItem(hWnd, RADIO_MEAN);
		hDisplay = GetDlgItem(hWnd, DISPLAY);
		hButton = GetDlgItem(hWnd, BUTTON1);





		return TRUE;

	case WM_COMMAND:
		if (wParam == BUTTON1) //MessageBox(hWnd, TEXT("kk"), L"zaza", MB_OK);


	return TRUE;
	}

	



	return FALSE;
}