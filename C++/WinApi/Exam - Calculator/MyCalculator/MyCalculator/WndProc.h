#pragma once
#include <Windows.h>
#include "resource.h"
#include "StringParsing.h"
#include <commctrl.h>
#pragma comment(lib,"comctl32")

#define HANDLE_MSG(message, fn)    \
    if((message) == wParam){ (fn)(hWnd, Message, wParam, lParam); \
	return TRUE;}


#define SHOW_STANDART_ELEMS(cmd)\
ShowWindow(GetDlgItem(hWnd,BTN_AC), cmd);\
ShowWindow(GetDlgItem(hWnd, BTN_BACKSPACE), cmd);\
ShowWindow(GetDlgItem(hWnd, BTN_LEFT_BRACKET), cmd);\
ShowWindow(GetDlgItem(hWnd, BTN_RIGHT_BRACKET), cmd);\
ShowWindow(GetDlgItem(hWnd, IDC_BUTTON7), cmd);\
ShowWindow(GetDlgItem(hWnd, IDC_BUTTON8), cmd);\
ShowWindow(GetDlgItem(hWnd, IDC_BUTTON9), cmd);\
ShowWindow(GetDlgItem(hWnd, BTN_DIV), cmd);

#define SHOW_MANUAL_ELEMS(cmd)\
ShowWindow(GetDlgItem(hWnd, BTN_EVAL), cmd); \
ShowWindow(GetDlgItem(hWnd, EDIT_RESULT), cmd);

#define RARIO_CHECK(id)	CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd), 0), MENU_STANDART_INPUT, MENU_MANUAL_INPUT, (id), MF_BYCOMMAND);

#define CHANGE_WINDOW_BOTTOM(n) GetWindowRect(hWnd, &posRect);\
MoveWindow(hWnd, posRect.left, posRect.top, sizeRect.right, sizeRect.bottom - (n), 1);




class WndProc
{

	StringParsing stringParcing;

	TCHAR text[50];
	TCHAR edit[50];
	char expression[50];

	HWND hEdit, hResult;

	HMENU hMenu;

	

	
	HWND hStatusBar, hSmallStatusBar;

	RECT sizeRect, posRect;


	bool Btn_Eq(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Menu_Manual(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Menu_Standart(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Btn_Eval(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);


public:

	bool Wm_Command(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Wm_Init(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

	WndProc();
	~WndProc();
};

