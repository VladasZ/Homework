// ���� WINDOWS.H �������� �����������, �������, � ���������
// ������� ������������ ��� ��������� ���������� ��� Windows.
#define UNICODE
#include <windows.h>
#include <tchar.h>
#include <string>

//�������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������"); /* ��� ������ ���� */

using namespace std;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;

	/* 1. ����������� ������ ����  */

	wcl.cbSize = sizeof(wcl);  // ������ ��������� WNDCLASSEX
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;   // ���� ������ �������� ��������� � ������� ������ (DBLCLK)
	wcl.lpfnWndProc = WindowProc;   // ����� ������� ���������
	wcl.cbClsExtra = 0;     // ������������ Windows
	wcl.cbWndExtra = 0;    // ������������ Windows
	wcl.hInstance = hInst;  // ���������� ������� ����������
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);    // �������� ����������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);      // �������� ������������ �������
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   //���������� ���� ����� ������         
	wcl.lpszMenuName = NULL;    // ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;  // ��� ������ ����
	wcl.hIconSm = NULL; // ���������� ��������� ������ ��� ����� � ������� ����


						/*  2. ����������� ������ ����  */

	if (!RegisterClassEx(&wcl))
		return 0;   // ��� ��������� ����������� - �����


					/*  3. �������� ����  */

					// ��������� ���� �  ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0,      // ����������� ����� ����
		szClassWindow,  // ��� ������ ����
		TEXT("Moving window"), // ��������� ����
										/* ���������, �����, ����������� ������ �������, ��������� ����,
										������ ������������ � ���������� ����  */
		WS_OVERLAPPEDWINDOW,    // ����� ����
		CW_USEDEFAULT,  // �-���������� ������ �������� ���� ����
		CW_USEDEFAULT,  // y-���������� ������ �������� ���� ����
		CW_USEDEFAULT,  // ������ ����
		CW_USEDEFAULT,  // ������ ����
		NULL,           // ���������� ������������� ����
		NULL,           // ���������� ���� ����
		hInst,      // ������������� ����������, ���������� ����
		NULL);      // ��������� �� ������� ������ ����������


					/* 4. ����������� ���� */

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // ����������� ����


						/* 5. ������ ����� ��������� ���������  */

						// ��������� ���������� ��������� �� ������� ���������
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);   // ���������� ���������
		DispatchMessage(&lpMsg);    // ��������������� ���������
	}
	return lpMsg.wParam;
}




LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{

	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);

	static int posX = 0;
	static int posY = 0;


	TCHAR str[50];
	switch (uMessage)
	{

	case WM_TIMER:

		if (posX <= screenX - 300 && posY == 0) {
			MoveWindow(hWnd, posX, 0, 300, 300, 1);
			posX += 10;
		}
		if (posX == screenX - 300 && posY <= screenY - 300) {
			MoveWindow(hWnd, posX, posY, 300, 300, 1);
			posY += 10;
		}
		if (posY == screenY - 300 && posX >= 0) {
			MoveWindow(hWnd, posX, posY, 300, 300, 1);
			posX -= 10;
		}
		if (posX == 0 && posY >= 0) {
			MoveWindow(hWnd, posX, posY, 300, 300, 1);
			posY -= 10;
		}



		break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN)

			SetTimer(hWnd, 1, 10, 0);

		if (wParam == VK_ESCAPE)
			KillTimer(hWnd, 1);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}