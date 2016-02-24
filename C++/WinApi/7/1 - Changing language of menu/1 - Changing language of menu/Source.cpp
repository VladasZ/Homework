#include <windows.h>
#include "resource.h"

#define CAT	1 
#define DOG 2
#define	MEOW 3
#define WOOF 4
#define	DIGITS 5
#define	ONE 6
#define TWO 7
#define THREE 8
#define ZOO 9
#define MENU 10 
#define HELLO 11
#define BYE 12


using namespace std;



HINSTANCE hInst;

HMENU hRusMenu, hEnMenu;
HMENU programmMenu, Menu, Cat, Dog, Zoo, Digits;
bool enMenu = true;

TCHAR text[50];

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
		

		hRusMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU2));
		hEnMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));

		Dog = CreatePopupMenu();

		AppendMenu(Dog, MF_POPUP, WOOF, TEXT("Woof!"));

		Cat = CreatePopupMenu();
		AppendMenu(Cat, MF_POPUP, MEOW, TEXT("Meow!"));

		Zoo = CreatePopupMenu();
		AppendMenu(Zoo, MF_POPUP, (UINT_PTR)Cat, TEXT("Cat"));
		AppendMenu(Zoo, MF_POPUP, (UINT_PTR)Dog, TEXT("Dog"));

		Digits = CreatePopupMenu();
		AppendMenu(Digits, MF_POPUP, ONE, TEXT("One"));
		AppendMenu(Digits, MF_POPUP, TWO, TEXT("Two"));
		AppendMenu(Digits, MF_POPUP, THREE, TEXT("Three"));

		Menu = CreatePopupMenu();
		AppendMenu(Menu, MF_POPUP, HELLO, TEXT("Hello"));
		AppendMenu(Menu, MF_POPUP, BYE, TEXT("Bye"));




		 programmMenu = CreateMenu();
		AppendMenu(programmMenu, MF_POPUP, (UINT_PTR)Menu, TEXT("Menu"));
		AppendMenu(programmMenu, MF_POPUP, (UINT_PTR)Zoo, TEXT("Zoo"));
		AppendMenu(programmMenu, MF_POPUP, (UINT_PTR)Digits, TEXT("Digits"));
		//SetMenu(hWnd, hEnMenu);


		return TRUE;

	case WM_COMMAND:

		if (wParam == ID_RES) {// switching menu with resourses
			if (enMenu) {
				SetMenu(hWnd, hRusMenu);
				enMenu = false;
			}
			else {
				SetMenu(hWnd, hEnMenu);
				enMenu = true;
			}
			return TRUE;
		}

		if (wParam == ID_PROGRAMM) {// switching menu in code
		
			if (!enMenu) {
				ModifyMenu(Dog, WOOF, 0, WOOF, L"Woof!");
				ModifyMenu(Cat, MEOW, 0, MEOW, L"Meow!");

				ModifyMenu(Digits, ONE, 0, ONE, L"One");
				ModifyMenu(Digits, TWO, 0, TWO, L"Two");
				ModifyMenu(Digits, THREE, 0, THREE, L"Three");

				ModifyMenu(Menu, HELLO, 0, HELLO, L"Hello");
				ModifyMenu(Menu, BYE, 0, BYE, L"Bye");
				enMenu = true;
				return TRUE;

			}
			else {
				ModifyMenu(Dog, WOOF, 0, WOOF, L"Гав!");
				ModifyMenu(Cat, MEOW, 0, MEOW, L"Мяу!");

				ModifyMenu(Digits, ONE, 0, ONE, L"Один");
				ModifyMenu(Digits, TWO, 0, TWO, L"Два");
				ModifyMenu(Digits, THREE, 0, THREE, L"Три");

				ModifyMenu(Menu, HELLO, 0, HELLO, L"Привет");
				ModifyMenu(Menu, BYE, 0, BYE, L"Пока");

				ModifyMenu(Zoo, 1, 0, 1, L"Кот");


				enMenu = false;
				//ModifyMenu(programmMenu,)
			}


			SetMenu(hWnd, programmMenu);

			return TRUE;
		}

		


	}



	return FALSE;
}