#include <windows.h>
#include "resource.h"
#include <algorithm>
#include <memory>



using namespace std;

#define newH make_shared<HWND>

HINSTANCE hInst;

TCHAR text[50];

enum size { left, right, top, bot };

class Game {
public:
	int field[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	HWND buttons[6][6];



	HWND activeButtons[4];

	struct EmptyPosition {
		int x;
		int y;
	}emptyPosition;

	
	void shuffle() {

		for (int i = 0; i < 1000; ++i) {
			swap(field[(rand() % 16) + 1], field[(rand() % 15) + 1]);
		}
	}

	void setActiveButtons() {

		bool brk = false;

		for (int i = 1; i < 5; ++i) {
			
			for (int j = 1; j < 5; ++j) {

				if (!buttons[j][i]) {

					emptyPosition.x = j;
					emptyPosition.y = i;


					activeButtons[top] = buttons[j - 1][i];
					activeButtons[bot] = buttons[j + 1][i];
					activeButtons[left] = buttons[j][i - 1];
					activeButtons[right] = buttons[j][i + 1];

					brk = true;

					break;


				}

			}
			if (brk) break;
		}

	}

	

	void init(HWND hWnd) {

		int n = 1;

		for (int i = 1; i < 5; ++i) {
			for (int j = 1; j < 5; ++j) {
				if (i == 4 && j == 4) break;
				wsprintf(text, TEXT("%d"), n++);

				buttons[j][i] = CreateWindowEx(0, TEXT("BUTTON"), text,
					WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
					j * 50, i * 50, 50, 50, hWnd, 0, hInst, 0);

			}
		}
	}

	void tellActive(){


		for (int i = 0; i < 4; ++i) {
			wsprintf(text, "%d %d", activeButtons[i])
		}

	}

	void show() {

	

		for (int i = 1; i < 5; ++i) {
			for (int j = 1; j < 5; ++j) {
			
				MoveWindow(buttons[j][i], j * 50, i * 50, 50, 50, 1);

			
			
			}
		}

	}




}game;

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

		game.init(hWnd);
		
		game.show();

		
		return TRUE;
	}



	return FALSE;
}