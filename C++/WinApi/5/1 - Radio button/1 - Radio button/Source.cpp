#include <windows.h>
#include "resource.h"
#include <vector>



using namespace std;



HINSTANCE hInst;
HWND hList, hAdd, hMult, hMean, hDisplay, hButton;

TCHAR text[50];

vector<int> values;



BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;


	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

void generateValues() {
	values.clear();

	for (int i = 0; i < 10 + (rand() % 10); ++i) {

		int n = 0;
		while (!n) n = -10 + (rand() % 20);

		values.push_back(n);

		wsprintf(text, TEXT("%d"), n);
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)text);
	}

}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;



	case WM_INITDIALOG:

		hList = GetDlgItem(hWnd, LIST1);
		hAdd = GetDlgItem(hWnd, RADIO_ADDITION);
		hMult = GetDlgItem(hWnd, RADIO_MULTIPLICATION);
		hMean = GetDlgItem(hWnd, RADIO_MEAN);
		hDisplay = GetDlgItem(hWnd, DISPLAY);
		hButton = GetDlgItem(hWnd, BUTTON1);

		generateValues();

		return TRUE;

	case WM_COMMAND:
		if (wParam == BUTTON1) { //MessageBox(hWnd, TEXT("kk"), L"zaza", MB_OK);
			SendMessage(hList, LB_RESETCONTENT, 0, 0);

			generateValues();


			if (IsDlgButtonChecked(hWnd, RADIO_ADDITION)) goto addition;
			if (IsDlgButtonChecked(hWnd, RADIO_MULTIPLICATION)) goto multiplication;
			if (IsDlgButtonChecked(hWnd, RADIO_MEAN)) goto mean;


			return TRUE;
		}

		



		if (LOWORD(wParam) == RADIO_ADDITION) {
			addition:
			int result = 0;

			for (auto a : values) result += a;

			wsprintf(text, L"%d", result);
			SetWindowText(hDisplay, text);
			return TRUE;
		}

		if (LOWORD(wParam) == RADIO_MULTIPLICATION) {
			multiplication:
			int result = 1;

			for (auto a : values) result *= a;

			wsprintf(text, L"%d", result);
			SetWindowText(hDisplay, text);
			return TRUE;
		}


		if (LOWORD(wParam) == RADIO_MEAN) {
			mean:
			int summ = 0;

			for (auto a : values) summ += a;

			int result = summ / (values.size());

			wsprintf(text, L"%d", result);
			SetWindowText(hDisplay, text);
			return TRUE;
		}


	return TRUE;
	}

	



	return FALSE;
}