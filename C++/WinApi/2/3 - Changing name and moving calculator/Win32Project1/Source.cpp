#include <windows.h>
#include <vector>
#include "resource.h"
#include <memory>

using namespace std;


#define LAST_STATIC statics[statics.size() - 1]
#define stat statics[i]

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

vector<shared_ptr<staticRect>> statics;

bool mouseDown;


TCHAR infoText[100];
HINSTANCE hInst;


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



		infoButton = GetDlgItem(hWnd, IDC_BUTTON1);// getting descriptor of the info button
		wsprintf(infoText, TEXT("Arrow: X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam));
		SetWindowText(infoButton, infoText);

		return TRUE;


	case WM_MOUSEMOVE:
		wsprintf(infoText, TEXT("Arrow: X=%d  Y=%d size= %d"), LOWORD(lParam), HIWORD(lParam), statics.size()); // mouse coordinates for info
		SetWindowText(infoButton, infoText);


		if (mouseDown)
		{


			MoveWindow(// changing size of new static when mouse is moving
				LAST_STATIC->handle,
				LAST_STATIC->x,
				LAST_STATIC->y,
				LOWORD(lParam) - LAST_STATIC->x,
				HIWORD(lParam) - LAST_STATIC->y,
				1
				);

			LAST_STATIC->height = LOWORD(lParam) - LAST_STATIC->x;
			LAST_STATIC->width = HIWORD(lParam) - LAST_STATIC->y;


		}


		for (int i = 0; i < statics.size(); ++i) {// showing info about statics


			if (LOWORD(lParam) > stat->x && LOWORD(lParam) < stat->x + stat->height
				&& HIWORD(lParam) > stat->y && HIWORD(lParam) < stat->y + stat->width) {

				wsprintf(infoText, TEXT("#%d, HIGHT = %d, WIDTH = %d, X position = %d, Y position = %d"), i, stat->height, stat->width, stat->x, stat->y);
				SetWindowText(hWnd, infoText);


				break;
			}
			else {
				wsprintf(infoText, TEXT("empty"), i, stat->height, stat->width, stat->x, stat->y);
				SetWindowText(hWnd, infoText);
			}
		}



		return TRUE;





	case WM_LBUTTONDOWN:

		mouseDown = true;

		statics.push_back
			(make_shared<staticRect>(
				CreateWindowEx(0, TEXT("STATIC"), 0,
					WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
					LOWORD(lParam), HIWORD(lParam), 0, 0, hWnd, 0, hInst, 0),
				LOWORD(lParam),
				HIWORD(lParam),
				0, 0)
				);





		return TRUE;

	case WM_LBUTTONUP:

		mouseDown = false;
		if (statics.size()) {
			if (LAST_STATIC->height < 10 && LAST_STATIC->width < 10 || LAST_STATIC->height < 0 || LAST_STATIC->height < 0) {// destroy static if it's less then 10*10
				DestroyWindow(LAST_STATIC->handle);
				statics.pop_back();
			}
		}

		mouseDown = false;

		if (statics.size()) {
			if (LAST_STATIC->height < 10 && LAST_STATIC->width < 10 || LAST_STATIC->height < 0 || LAST_STATIC->height < 0) {// destroy static if it's less then 10*10
				DestroyWindow(LAST_STATIC->handle);
				statics.pop_back();
			}
		}


		return TRUE;



		//moved to WM_MOUSEMOVE
		/*case WM_RBUTTONDOWN:
		for (int i = 0; i < statics.size(); ++i) {
		if (LOWORD(lParam) > stat->x && LOWORD(lParam) < stat->x + stat->height
		&& HIWORD(lParam) > stat->y && HIWORD(lParam) < stat->y + stat->width) {
		wsprintf(infoText, TEXT("#%d, HIGHT = %d, WIDTH = %d, X position = %d, Y position = %d"), i, stat->height, stat->width, stat->x, stat->y);
		SetWindowText(hWnd, infoText);
		break;
		}
		else {
		wsprintf(infoText, TEXT("empty"), i, stat->height, stat->width, stat->x, stat->y);
		SetWindowText(hWnd, infoText);
		}
		}
		return TRUE;*/

	case WM_LBUTTONDBLCLK:


		if (statics.size()) {
			for (int i = 0; i < statics.size(); ++i) {


				if (LOWORD(lParam) > stat->x && LOWORD(lParam) < stat->x + stat->height
					&& HIWORD(lParam) > stat->y && HIWORD(lParam) < stat->y + stat->width) {

					DestroyWindow(stat->handle);

					statics.erase(statics.begin() + i);

					break;

				}
			}
		}

		return TRUE;
	}
	return FALSE;
}