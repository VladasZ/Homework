#include <windows.h>
#include "resource.h"



using namespace std;



HINSTANCE hInst;


TCHAR text[50];

HMENU hMenu, hButton, hEdit, hStatic, hSubMenu;

int edit = 3, button = 3, _static = 3;

POINT mouse;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;


	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;



	case WM_INITDIALOG:


		hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));

		hSubMenu = GetSubMenu(hMenu, 0);
		hButton = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(ID_MENU_BUTTON));
		hStatic = GetSubMenu(hMenu, 1);

		

		//ModifyMenu(hButton, ID_MENU_BUTTON, 0, ID_MENU_BUTTON, L"pixdeeec");
		return TRUE;

	case WM_COMMAND:
		if (wParam == ID_MENU_BUTTON) {
			


			GetCursorPos(&mouse);
			ScreenToClient(hWnd,&mouse);

			wsprintf(text, L"Button %d", button--);
			CreateWindowEx(0, TEXT("BUTTON"), text,
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
				mouse.x, mouse.y, 100, 40, hWnd, 0, hInst, 0);

			wsprintf(text, L"Button %d", button);
			ModifyMenu(hSubMenu, ID_MENU_BUTTON, 0, ID_MENU_BUTTON, text);

			if (button == 0) {
				DeleteMenu(hSubMenu, ID_MENU_BUTTON, 0);
			}
			return TRUE;

		}
		
		if (wParam == ID_MENU_EDIT) {

			GetCursorPos(&mouse);
			ScreenToClient(hWnd, &mouse);

			wsprintf(text, L"Edit %d", edit--);
			CreateWindowEx(0, TEXT("EDIT"), text,
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
				mouse.x, mouse.y, 100, 40, hWnd, 0, hInst, 0);

			wsprintf(text, L"Edit %d", edit);
			ModifyMenu(hSubMenu, ID_MENU_EDIT, 0, ID_MENU_EDIT, text);

			if (edit == 0) {
				DeleteMenu(hSubMenu, ID_MENU_EDIT, 0);
			}

			return TRUE;

		}


		if (wParam == ID_MENU_STATIC) {



			GetCursorPos(&mouse);
			ScreenToClient(hWnd, &mouse);

			wsprintf(text, L"Static %d", _static--);
			CreateWindowEx(0, TEXT("STATIC"), text,
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
				mouse.x, mouse.y, 100, 40, hWnd, 0, hInst, 0);

			wsprintf(text, L"Static %d", _static);
			ModifyMenu(hSubMenu, ID_MENU_STATIC, 0, ID_MENU_STATIC, text);

			if (_static == 0) {
				DeleteMenu(hSubMenu, ID_MENU_STATIC, 0);
			}
			return TRUE;

		}



	case WM_CONTEXTMENU:
		TrackPopupMenu(hSubMenu, TPM_LEFTALIGN, LOWORD(lParam), HIWORD(lParam), 0, hWnd, 0);

		return TRUE;
	}



	return FALSE;
}