
// Файл WINDOWS.H содержит определения, макросы, и структуры
// которые используются при написании приложений под Windows.
#include <windows.h>
#include <tchar.h>
#include <string>



using namespace std;


//прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);


TCHAR szClassWindow[] = TEXT("Каркасное приложение"); /* Имя класса окна */


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;


	/* 1. Определение класса окна */


	wcl.cbSize = sizeof(wcl); // размер структуры WNDCLASSEX
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; // окно сможет получать сообщения о двойном щелчке (DBLCLK)
	wcl.lpfnWndProc = WindowProc; // адрес оконной процедуры
	wcl.cbClsExtra = 0; // используется Windows
	wcl.cbWndExtra = 0; // используется Windows
	wcl.hInstance = hInst; // дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); // загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); // загрузка стандартного курсора
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //заполнение окна белым цветом 
	wcl.lpszMenuName = NULL; // приложение не содержит меню
	wcl.lpszClassName = szClassWindow; // имя класса окна
	wcl.hIconSm = NULL; // отсутствие маленькой иконки для связи с классом окна



						/* 2. Регистрация класса окна */


	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход



				  /* 3. Создание окна */


				  // создается окно и переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0, // расширенный стиль окна
		szClassWindow, // имя класса окна
		TEXT("Каркас Windows приложения"), // заголовок окна
										   /* Заголовок, рамка, позволяющая менять размеры, системное меню,
										   кнопки развёртывания и свёртывания окна */
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT, // х-координата левого верхнего угла окна
		CW_USEDEFAULT, // y-координата левого верхнего угла окна
		CW_USEDEFAULT, // ширина окна
		CW_USEDEFAULT, // высота окна
		NULL, // дескриптор родительского окна
		NULL, // дескриптор меню окна
		hInst, // идентификатор приложения, создавшего окно
		NULL); // указатель на область данных приложения



			   /* 4. Отображение окна */


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна



						/* 5. Запуск цикла обработки сообщений */


						// получение очередного сообщения из очереди сообщений
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg); // трансляция сообщения
		DispatchMessage(&lpMsg); // диспетчеризация сообщений
	}
	return lpMsg.wParam;
}





TCHAR* whereClick(const RECT& lpRect, const int& x, const int& y) {

	if (x == 20 || y == 20 ||
		x == lpRect.right - 20 || y == lpRect.bottom - 20) return TEXT("Click on border");


	if (x < 20 || y < 20 ||
		x > lpRect.right - 20 || y > lpRect.bottom - 20) return TEXT("Click outside the border");


	if (x > 20 || y > 20 ||
		x < lpRect.right - 20 || y < lpRect.bottom - 20) return TEXT("Click inside the border");



}



LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[50];
	RECT lpRect;
	int mouseX, mouseY;


	GetWindowRect(hWnd, &lpRect);


	switch (uMessage)
	{


	case WM_LBUTTONDOWN:
		mouseX = LOWORD(lParam); // getting mouse coordinates 
		mouseY = HIWORD(lParam);
		GetClientRect(hWnd, &lpRect); // getting size of window


		SetWindowText(hWnd, whereClick(lpRect, mouseX, mouseY)); // строка выводится в заголовок окна

		break;


	case WM_RBUTTONDOWN:
		GetClientRect(hWnd, &lpRect); // getting size of window


		wsprintf(str, TEXT("Size of window: x = %d y = %d"), lpRect.right, lpRect.bottom);


		MessageBox(
			0,str,
			TEXT("Window info"),
			MB_OK | MB_ICONINFORMATION);



		break;
	case WM_DESTROY: // сообщение о завершении программы
		PostQuitMessage(0); // посылка сообщения WM_QUIT
		break;
	default:
		// все сообщения, которые не обрабатываются в данной оконной
		// функции направляются обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}