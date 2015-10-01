#include <windows.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hStatic1, hStatic2;
TCHAR szCoordinates[20];
HINSTANCE hInst;
const int LEFT = 15, TOP = 110, WIDTH = 380, HEIGHT = 50;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;
	// ������ ������� ���� ���������� �� ������ ���������� �������
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0); // ��������� ��������� ������
		return TRUE;
		// WM_INITDIALOG - ������ ��������� �������� ����� �������� ����������� ����, �� ����� ��� ������������ �� �����
	case WM_INITDIALOG:
		hStatic1 = GetDlgItem(hWnd, IDC_STATIC1); // �������� ���������� �������, ������������ �� ����� �������
												  //������ ������ � ������� CreateWindowEx
		hStatic2 = CreateWindowEx(0, TEXT("STATIC"), 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
			LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0);
		return TRUE;
	case WM_MOUSEMOVE:
		wsprintf(szCoordinates, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // ������� ���������� ������� ����
		SetWindowText(hStatic1, szCoordinates);	// ������ ��������� �� ������
		return TRUE;
	case WM_LBUTTONDOWN:
		SetWindowText(hStatic2, TEXT("������ ����� ������ ����"));
		return TRUE;
	case WM_RBUTTONDOWN:
		SetWindowText(hStatic2, TEXT("������ ������ ������ ����"));
		return TRUE;
	}
	return FALSE;
}