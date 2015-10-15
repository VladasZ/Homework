#include <windows.h>
#include "resource.h"
#include <algorithm>
#include <memory>



using namespace std;

#define ID_BUTTON1 1
#define ID_BUTTON2 2
#define ID_BUTTON3 3
#define ID_BUTTON4 4
#define ID_BUTTON5 5
#define ID_BUTTON6 6
#define ID_BUTTON7 7
#define ID_BUTTON8 8
#define ID_BUTTON9 9
#define ID_BUTTON10 10
#define ID_BUTTON11 11
#define ID_BUTTON12 12
#define ID_BUTTON13 13
#define ID_BUTTON14 14
#define ID_BUTTON15 15

#define FOR_EACH_FIELD_ELEM for (int i = 1; i < 5; ++i) { for (int j = 1; j < 5; ++j) {
#define END_FOR_EACH }}
#define ELEM field[j][i]

#define EMPTY_ELEM game.field[game.emptyX][game.emptyY]

HINSTANCE hInst;

TCHAR text[50];

enum size { left, right, top, bot };

struct Button {
	int number;
	HWND hWnd;
	bool enable;

};



class Game {
public:
	Button field[6][6];

	int emptyX=4, emptyY=4;




	static void goToPos(HWND hWnd,int id, int x, int y) {
		MoveWindow(GetDlgItem(hWnd, id),
			x*50,
			y*50,
			50,
			50,
			1
			);
	
	
	}

	void shuffle(HWND hWnd) {


		int n = 1;

		for (int p = 0; p < 3000; ++p) {

			n = rand() % 15 + 1;


			FOR_EACH_FIELD_ELEM


				if (game.ELEM.number == n && game.ELEM.enable) {
					Game::goToPos(hWnd, n, game.emptyX, game.emptyY);
					swap(game.ELEM, EMPTY_ELEM);
					game.setActiveButtons();
					goto _break;
				}

			END_FOR_EACH

				_break : ;
		}
	}


	int setActiveButtons() {


		FOR_EACH_FIELD_ELEM

				ELEM.enable = false; // resetting old values

		END_FOR_EACH




			for (int i = 1; i < 5; ++i) {
				for (int j = 1; j < 5; ++j) {

					ELEM.enable = false;

					if (!ELEM.hWnd) {
						emptyX = j; emptyY = i;
						field[j - 1][i].enable = true;
						field[j + 1][i].enable = true;
						field[j][i - 1].enable = true;
						field[j][i + 1].enable = true;
						return 1;
					}

				}
			}

		
	
		return 0;

	}


	void init(HWND hWnd) {


		int n = 0;

		FOR_EACH_FIELD_ELEM

			if (j == 4 && i == 4) continue;

				wsprintf(text, TEXT("%d"), ++n);

			ELEM.hWnd = CreateWindowEx(0, TEXT("BUTTON"), text,
					WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
					j * 50, i * 50, 50, 50, hWnd, (HMENU)n, hInst, 0);
			ELEM.number = n;

			ELEM.enable = false;


		END_FOR_EACH


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
		game.setActiveButtons();
		game.shuffle(hWnd);
		

		

		return TRUE;

	case WM_COMMAND:

		if (wParam == BTN_SHUFFLE) {
			game.shuffle(hWnd);

			return TRUE;
		}
		
		FOR_EACH_FIELD_ELEM


				if (game.ELEM.number == wParam && game.ELEM.enable) {
					Game::goToPos(hWnd, wParam, game.emptyX, game.emptyY);
					swap(game.ELEM, EMPTY_ELEM);
					game.setActiveButtons();
					return TRUE;
				}

		END_FOR_EACH

			return TRUE;
	}



	return FALSE;
}