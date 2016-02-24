#include <windows.h>
#include "resource.h"
#include <string>



using namespace std;



HINSTANCE hInst;

TCHAR fOper[20];
TCHAR sOper[20];
TCHAR sign[20];
TCHAR text[20];
int firstValue, secondValue, result;

HWND hFOper, hSOper, hSign, hResult;



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
		hFOper = GetDlgItem(hWnd, ED_FIRST_OPERAND);
		hSOper = GetDlgItem(hWnd, ED_SECOND_OPERAND);
		hSign = GetDlgItem(hWnd, ED_OPERATION);
		hResult = GetDlgItem(hWnd, STAT_RESULT);
		SetWindowText(hWnd, TEXT("Calculator"));


		return TRUE;

	case WM_COMMAND:
		if (wParam == BTN_CALCULATE) {
			if (!GetWindowText(hFOper, fOper, 20)) {
				SetWindowText(hResult, TEXT("Error! Enter first value"));
				return TRUE;
			}
			if (!GetWindowText(hSOper, sOper, 20)) {
			SetWindowText(hResult, TEXT("Error! Enter second value"));
			return TRUE;
			}
			GetWindowText(hSign, sign, 20);



			if (lstrcmp(sign, TEXT("+")) &&
				lstrcmp(sign, TEXT("-")) &&
				lstrcmp(sign, TEXT("/")) &&
				lstrcmp(sign, TEXT("*"))) {
				SetWindowText(hResult, TEXT("Error! Wrong operator"));
				return TRUE;
			}

			if (!lstrcmp(sign, TEXT("/")) &&
				!lstrcmp(sOper, TEXT("0"))) {
				SetWindowText(hResult, TEXT("Error! Dividing by zero"));
				return TRUE;
			}

			firstValue = stoi(fOper);
			secondValue = stoi(sOper);

			if (!lstrcmp(sign, TEXT("+"))) result = firstValue + secondValue;
			if (!lstrcmp(sign, TEXT("-"))) result = firstValue - secondValue;
			if (!lstrcmp(sign, TEXT("/"))) result = firstValue / secondValue;
			if (!lstrcmp(sign, TEXT("*"))) result = firstValue * secondValue;

			wsprintf(text, TEXT("%d"), result);
			SetWindowText(hResult, text);

			return TRUE;
		}
	}



	return FALSE;
}