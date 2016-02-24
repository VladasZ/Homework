#include <windows.h>
#include "resource.h"
#include <Commctrl.h>
#include <ctime>


using namespace std;

HANDLE Threads[3];
HWND Slides[3];

HINSTANCE hInst;

TCHAR text[50];

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;


	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

DWORD WINAPI threadProc(CONST LPVOID lpParam) {

	srand((int)lpParam);

	while (7) {
		SendMessage(Slides[(int)lpParam], PBM_SETPOS, rand() % 101, 0);
		Sleep(75);
	}
}


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;



	case WM_INITDIALOG:

		Threads[0] = CreateThread(NULL, 0, threadProc, (LPVOID)0, 0, NULL);

		Threads[1] = CreateThread(NULL, 0, threadProc, (LPVOID)1, 0, NULL);

		Threads[2] = CreateThread(NULL, 0, threadProc, (LPVOID)2, 0, NULL);

		Slides[0] = GetDlgItem(hWnd, IDC_PROGRESS1);
		Slides[1] = GetDlgItem(hWnd, IDC_PROGRESS2);
		Slides[2] = GetDlgItem(hWnd, IDC_PROGRESS3);



		return TRUE;
	}



	return FALSE;
}