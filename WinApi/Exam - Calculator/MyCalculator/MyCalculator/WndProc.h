#pragma once
#include <Windows.h>
#include "resource.h"
#include "StringParsing.h"
#include <commctrl.h>


#define HANDLE_MSG(message, fn)    \
    if((message) == wParam){ (fn)(hWnd, Message, wParam, lParam); \
	return TRUE;}


#pragma comment(lib,"comctl32")

class WndProc
{

	StringParsing stringParcing;

	TCHAR text[50];
	TCHAR edit[50];
	char expression[50];

	HWND hEdit;

	HMENU hMenu;

	typedef bool(*dllFunc)(const TCHAR[]);

	dllFunc checkBrackets;

	HINSTANCE hLib;
	HWND hStatusBar;

	RECT rect;


	bool Btn_Eq(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Menu_Manual(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Menu_Standart(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);


public:

	bool Wm_Command(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	bool Wm_Init(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

	WndProc();
	~WndProc();
};

