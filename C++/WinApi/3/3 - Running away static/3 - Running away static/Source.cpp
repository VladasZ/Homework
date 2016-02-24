#include <windows.h>
#include <vector>
#include "resource.h"
#include <memory>

using namespace std;

#define X LOWORD(lParam) 
#define Y HIWORD(lParam)



BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);



HWND bYes, bNo, info;


struct Rect {
	HWND handl;
	int x, y, hight, width;


	void set(
		int x, int y, int hight, int width) {

		this->x = x;
		this->y = y;
		this->hight = hight;
		this->width = width;
	}
	/*Rect();
	Rect(HWND handl,
	int x, int y, int hight, int width) : handl(handl), x(x), y(y), hight(hight), width(width) {}*/
};


//Rect noRect;

RECT noRect;

TCHAR infoText[100];
HINSTANCE hInst;



void goToRect(const HWND& hWnd, const LPRECT& rect) {
	MoveWindow(hWnd, rect->left, rect->top, rect->right - rect->left, rect->top - rect->bottom, 1);

}


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
		bYes = GetDlgItem(hWnd, BTN_YES);
		bNo = GetDlgItem(hWnd, BTN_NO);
		info = GetDlgItem(hWnd, STAT_INFO);
		SetWindowText(hWnd, TEXT("Опрос"));




		return TRUE;

	case WM_MOUSEMOVE:




		GetWindowRect(bNo, &noRect);
		ScreenToClient(hWnd, &noRect);


		wsprintf(infoText, TEXT("X=%d Y=%d\n bot - %d left - %dright - %d top - %d"), LOWORD(lParam), HIWORD(lParam), noRect.bottom, noRect.left, noRect.right, noRect.top);
		SetWindowText(info, infoText);

		/*wsprintf(infoText, TEXT("%d"), GetClientRect(bNo, &noRect));
		SetWindowText(hWnd, infoText);*/





		if (X < noRect.left - 10 && X > noRect.left - 20) {
			//noRect.bottom++;
			//noRect.left++;
			//noRect.right++;
			//noRect.top++;
			//goToRect(bNo, &noRect);
		}




		return TRUE;


	}
	return FALSE;
}