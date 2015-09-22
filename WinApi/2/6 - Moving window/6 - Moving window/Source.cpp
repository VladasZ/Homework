// Файл WINDOWS.H содержит определения, макросы, и структуры
// которые используются при написании приложений под Windows.
#define UNICODE
#include <windows.h>
#include <tchar.h>
#include <string>

//прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение"); /* Имя класса окна */

using namespace std;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;

	/* 1. Определение класса окна  */

	wcl.cbSize = sizeof(wcl);  // размер структуры WNDCLASSEX
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;   // окно сможет получать сообщения о двойном щелчке (DBLCLK)
	wcl.lpfnWndProc = WindowProc;   // адрес оконной процедуры
	wcl.cbClsExtra = 0;     // используется Windows
	wcl.cbWndExtra = 0;    // используется Windows
	wcl.hInstance = hInst;  // дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);    // загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);      // загрузка стандартного курсора
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   //заполнение окна белым цветом         
	wcl.lpszMenuName = NULL;    // приложение не содержит меню
	wcl.lpszClassName = szClassWindow;  // имя класса окна
	wcl.hIconSm = NULL; // отсутствие маленькой иконки для связи с классом окна


						/*  2. Регистрация класса окна  */

	if (!RegisterClassEx(&wcl))
		return 0;   // при неудачной регистрации - выход


					/*  3. Создание окна  */

					// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,      // расширенный стиль окна
		szClassWindow,  // имя класса окна
		TEXT("Moving window"), // заголовок окна
										/* Заголовок, рамка, позволяющая менять размеры, системное меню,
										кнопки развёртывания и свёртывания окна  */
		WS_OVERLAPPEDWINDOW,    // стиль окна
		CW_USEDEFAULT,  // х-координата левого верхнего угла окна
		CW_USEDEFAULT,  // y-координата левого верхнего угла окна
		CW_USEDEFAULT,  // ширина окна
		CW_USEDEFAULT,  // высота окна
		NULL,           // дескриптор родительского окна
		NULL,           // дескриптор меню окна
		hInst,      // идентификатор приложения, создавшего окно
		NULL);      // указатель на область данных приложения


					/* 4. Отображение окна */

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна


						/* 5. Запуск цикла обработки сообщений  */

						// получение очередного сообщения из очереди сообщений
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);   // трансляция сообщения
		DispatchMessage(&lpMsg);    // диспетчеризация сообщений
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