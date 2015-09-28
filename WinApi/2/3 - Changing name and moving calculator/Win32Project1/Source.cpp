#include <windows.h>
#include <vector>

using namespace std;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam);
BOOL CALLBACK FindDialog(HWND hWnd, LPARAM lParam);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Перечисление дочерних окон"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);



	HWND h = FindWindow(TEXT("CalcFrame"), NULL); // получим дескриптор "Калькулятора"
	if (!h)
		MessageBox(hWnd, TEXT("Необходимо открыть \"Калькулятор\""), TEXT("Error!!!"), MB_OK | MB_ICONSTOP);

	else
		EnumChildWindows(h, EnumChildProc, (LPARAM)hWnd); // начинаем перечисление дочерних окон "Калькулятора"


	//EnumChildWindows(h, FindDialog, (LPARAM)hWnd); // начинаем перечисление дочерних окон "Калькулятора"


	//MessageBox(hWnd, TEXT("Откройте, пожалуйста, \"Калькулятор\", и нажмите <CTRL>"), TEXT("Перечисление дочерних окон"), MB_OK | MB_ICONINFORMATION);
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

vector<HWND> buttons;


BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam)
{
	HWND hWindow = (HWND)lParam; // дескриптор окна нашего приложения
	TCHAR caption[MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
	
	GetClassName(hWnd, classname, 100); // получаем имя класса текущего дочернего окна

	if (wcscmp(classname , TEXT("Button"))) {
		

		buttons.push_back(hWnd);

	}
	else {
		//MessageBox(hWindow, TEXT("izi"), TEXT("Ok"), MB_OK);

	}
	
	return TRUE; // продолжаем перечисление дочерних окон
}

BOOL CALLBACK FindDialog(HWND hWnd, LPARAM lParam)
{
	HWND hWindow = (HWND)lParam; // дескриптор окна нашего приложения
	TCHAR caption[MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
	GetClassName(hWnd, classname, 100); // получаем имя класса текущего дочернего окна

	if (wcscmp(classname, TEXT("#32770 (Dialog)"))) {
		MessageBox(hWindow, TEXT("OK dialog"), TEXT("Ok"), MB_OK );

		buttons.push_back(hWnd);

	}
	else {
		MessageBox(hWindow, TEXT("izi"), TEXT("Ok"), MB_OK);

	}

	return TRUE; // продолжаем перечисление дочерних окон
}



LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int number = 0;

	
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_CONTROL)
		{
			}
		if (wParam == VK_RETURN)
		{
			ShowWindow(buttons[number], SW_HIDE);
		}
		if (wParam == VK_ESCAPE)
		{
			ShowWindow(buttons[number], SW_SHOW);
		}
		if (wParam == VK_UP)
		{
			++number;
		}
		if (wParam == VK_DOWN)
		{
			--number;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

