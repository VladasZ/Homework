#include "TaskManager.h"





void TaskManager::showProcesses() {
	SendMessage(hSystemProcessesList, LB_RESETCONTENT, 0, 0);

	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	memset(&pe32, 0, sizeof(PROCESSENTRY32));
	pe32.dwSize = sizeof(PROCESSENTRY32);


	if (Process32First(hSnapShot, &pe32))
	{
		wsprintf(text, pe32.szExeFile);

		SendMessage(hSystemProcessesList, LB_ADDSTRING, 0, (WPARAM)text);

		while (Process32Next(hSnapShot, &pe32))
		{
			wsprintf(text, pe32.szExeFile);

			SendMessage(hSystemProcessesList, LB_ADDSTRING, 0, (WPARAM)text);
		}
	}
}

void TaskManager::showInfo(const int& a)
{
	wsprintf(text, L"%d", a);
	SetWindowText(hWnd, text);
}

void TaskManager::showInfo(LPCTSTR a) {
	wsprintf(text, a);
	SetWindowText(hWnd, text);
}

int TaskManager::closeProcess(LPCTSTR name)
{
	HANDLE kill = getProcessHandle(name);

	TerminateProcess(kill, 0);

	return 1;
}


void TaskManager::init(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	hEdit = GetDlgItem(hWnd, ED_EDIT1);// initializing hadles for the dialog elements
	hStart = GetDlgItem(hWnd, BTN_START);
	hRefresh = GetDlgItem(hWnd, BTN_REFRESH);
	hSystemProcessesList = GetDlgItem(hWnd, LST_OPEN_TASKS);
	hToEndProcessesList = GetDlgItem(hWnd, LST_TASKS_TO_END);
	hMoveRight = GetDlgItem(hWnd, BTN_ADD_TO_RIGHT);
	hMoveLeft = GetDlgItem(hWnd, BTN_ALL_TO_LEFT);
	hMoveAllRight = GetDlgItem(hWnd, BTN_ALL_TO_RIGHT);
	hMoveAllLeft = GetDlgItem(hWnd, BTN_ALL_TO_LEFT);
	hEndTask = GetDlgItem(hWnd, BTN_END_TASK);
	this->hWnd = hWnd;

	showProcesses();

}

HANDLE TaskManager::getProcessHandle(LPCTSTR name) {

	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	memset(&pe32, 0, sizeof(PROCESSENTRY32));
	pe32.dwSize = sizeof(PROCESSENTRY32);


	if (Process32First(hSnapShot, &pe32))
	{
		if (!lstrcmp(name, pe32.szExeFile))

		return OpenProcess((DWORD)PROCESS_ALL_ACCESS, true, (DWORD)pe32.th32ProcessID);

		

		while (Process32Next(hSnapShot, &pe32))
		{

			if (!lstrcmp(name, pe32.szExeFile))

			return OpenProcess((DWORD)PROCESS_ALL_ACCESS, true, (DWORD)pe32.th32ProcessID);
		}
	}

	return 0;
}





int TaskManager::wmCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	if (wParam == BTN_REFRESH) {
		showProcesses();
		return 1;
	}


	if (wParam == BTN_ADD_TO_RIGHT) {

		if (SendMessage(hSystemProcessesList, LB_GETCURSEL, 0, 0) != -1) {

			SendMessage(hSystemProcessesList, LB_GETTEXT,
				SendMessage(hSystemProcessesList, LB_GETCURSEL, 0, 0),
				(WPARAM)text);

			SendMessage(hSystemProcessesList, LB_DELETESTRING,
				SendMessage(hSystemProcessesList, LB_GETCURSEL, 0, 0),
				(WPARAM)text);

			SendMessage(hToEndProcessesList, LB_ADDSTRING, 0, (WPARAM)text);
		}
		return 1;
	}


	if (wParam == BNT_ADD_TO_LEFT) {

		if (SendMessage(hToEndProcessesList, LB_GETCURSEL, 0, 0) != -1) {

			SendMessage(hToEndProcessesList, LB_GETTEXT,
				SendMessage(hToEndProcessesList, LB_GETCURSEL, 0, 0),
				(WPARAM)text);

			SendMessage(hToEndProcessesList, LB_DELETESTRING,
				SendMessage(hToEndProcessesList, LB_GETCURSEL, 0, 0),
				(WPARAM)text);

			SendMessage(hSystemProcessesList, LB_ADDSTRING, 0, (WPARAM)text);
		}
		return 1;
	}

	if (wParam == BTN_END_TASK) {


		int i = SendMessage(hToEndProcessesList, LB_GETCOUNT, 0, 0) * 2;

		while (i--) {

			SendMessage(hToEndProcessesList, LB_GETTEXT, 0, (WPARAM)text);

			closeProcess(text);

			SendMessage(hToEndProcessesList, LB_DELETESTRING, 0, 0);


		}

		return 1;
	}

}

int TaskManager::dblClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	SendMessage(hToEndProcessesList, LB_GETTEXT, 0, (WPARAM)text);

	closeProcess(text);

	SendMessage(hToEndProcessesList, LB_DELETESTRING, 0, 0);

	


	return 0;
}
