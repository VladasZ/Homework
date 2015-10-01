#include <windows.h>
#include <vector>
#include "resource.h"

using namespace std;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hStatic1, hStatic2;
HWND newStatic;
HWND infoButton;

struct staticRect {
	HWND handle;
	int x;
	int y;
	int width;
	int height;

	staticRect(HWND hwnd, int x, int y, int width, int height) : handle(hwnd), x(x), y(y), width(width), height(height) {}
};

vector<staticRect*> statics;

bool mouseDown;


TCHAR infoText[100];
HINSTANCE hInst;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;
	// создаём главное окно приложения на основе модального диалога
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0); // закрываем модальный диалог
		return TRUE;
		// WM_INITDIALOG - данное сообщение приходит после создания диалогового окна, но перед его отображением на экран
	case WM_INITDIALOG:
		//	hStatic1 = GetDlgItem(hWnd, IDC_STATIC1); // получаем дескриптор статика, размещенного на форме диалога
		//создаём статик с помощью CreateWindowEx
			
		/*hStatic2 = CreateWindowEx(0, TEXT("STATIC"), 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
			LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0);*/


		infoButton = GetDlgItem(hWnd, IDC_BUTTON1);
		wsprintf(infoText, TEXT("Arrow: X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // текущие координаты курсора мыши
		SetWindowText(infoButton, infoText);	// строка выводится на статик

		return TRUE;


	case WM_MOUSEMOVE:
		wsprintf(infoText, TEXT("Arrow: X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // текущие координаты курсора мыши
		SetWindowText(infoButton, infoText);	// строка выводится на статик


		if (mouseDown)
		{

			
			MoveWindow(
				statics[statics.size() - 1]->handle,
				statics[statics.size() - 1]->x,
				statics[statics.size() - 1]->y,
				LOWORD(lParam) - statics[statics.size() - 1]->x,
				HIWORD(lParam) - statics[statics.size() - 1]->y,
				1
				);

		}


		return TRUE;





	case WM_LBUTTONDOWN:

		mouseDown = true;

		statics.push_back
			( new staticRect(
				CreateWindowEx(0, TEXT("STATIC"), 0,
					WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
					LOWORD(lParam), HIWORD(lParam), 0, 0, hWnd, 0, hInst, 0), 
				LOWORD(lParam),
				HIWORD(lParam),
				0,0)
				);

	



		return TRUE;

	case WM_LBUTTONUP:
			mouseDown = false;

		return TRUE;
	case WM_RBUTTONDOWN:
		
		return TRUE;
	}
	return FALSE;
}