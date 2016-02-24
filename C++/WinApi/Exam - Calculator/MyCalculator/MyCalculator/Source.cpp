#include <Windows.h>
#include "resource.h"
#include "WndProc.h"

using namespace std;

#define HANDLE_MSG(message, fn)    \
    case (message): (fn)(hWnd, Message, wParam, lParam)

HINSTANCE hInst;
WndProc wndProc;

BOOL CALLBACK DlgProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	hInst = hInstance;

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {

	switch (Message)
	{

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;


		HANDLE_MSG(WM_INITDIALOG, wndProc.Wm_Init);
		HANDLE_MSG(WM_COMMAND, wndProc.Wm_Command);



	default:
		break;
	}
	

	return FALSE;

}


