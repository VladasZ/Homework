// Check Brackets DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern "C" __declspec(dllexport)
bool checkBrackets(const TCHAR strng[]) {
	char openHook = '(';
	char closeHook = ')';





	int open = 0;
	int close = 0;
	char firstHook = 0;
	char lastHook = 0;

	for (int i = 0; i <= wcslen(strng); i++) {


		if (strng[i] == openHook) {

			if (!firstHook) {
				firstHook = openHook;
			}

			lastHook = openHook;

			open++;
		}



		if (strng[i] == closeHook) {

			if (!firstHook) {
				firstHook = closeHook;
			}

			lastHook = closeHook;

			close++;
		}

	}


	if (open == close &&
		firstHook != closeHook   &&
		lastHook != openHook)
	{
		return true;
	}
	return false;
}