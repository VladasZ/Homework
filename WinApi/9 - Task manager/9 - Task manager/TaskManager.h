#pragma once
#include <windows.h>
#include "resource.h"
#include <TlHelp32.h>

class TaskManager
{
	HWND hEdit, hStart, hRefresh,
		hSystemProcessesList,
		hToEndProcessesList, 
		hMoveRight,
		hMoveLeft,
		hMoveAllRight,
		hMoveAllLeft,
		hEndTask, hWnd;

	HANDLE hSnapShot;
	PROCESSENTRY32 pe32;

	TCHAR text[50];

	void showProcesses();

	void showInfo(const int& a);

	void showInfo(LPCTSTR a);

	int closeProcess(LPCTSTR name);

	HANDLE getProcessHandle(LPCTSTR name);

public:
	void init(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	int wmCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	int dblClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

