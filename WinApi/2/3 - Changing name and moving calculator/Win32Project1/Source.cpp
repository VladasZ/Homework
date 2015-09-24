// ‘айл WINDOWS.H содержит определени€, макросы, и структуры
// которые используютс€ при написании приложений под Windows.
#define UNICODE
#include <windows.h>
#include <tchar.h>
#include <string>


//прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);


TCHAR szClassWindow[] = TEXT(" аркасное приложение"); /* »м€ класса окна */


using namespace std;


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;


	/* 1. ќпределение класса окна */


	wcl.cbSize = sizeof(wcl); // размер структуры WNDCLASSEX
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; // окно сможет получать сообщени€ о двойном щелчке (DBLCLK)
	wcl.lpfnWndProc = WindowProc; // адрес оконной процедуры
	wcl.cbClsExtra = 0; // используетс€ Windows
	wcl.cbWndExtra = 0; // используетс€ Windows
	wcl.hInstance = hInst; // дескриптор данного приложени€
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); // загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); // загрузка стандартного курсора
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //заполнение окна белым цветом 
	wcl.lpszMenuName = NULL; // приложение не содержит меню
	wcl.lpszClassName = szClassWindow; // им€ класса окна
	wcl.hIconSm = NULL; // отсутствие маленькой иконки дл€ св€зи с классом окна



						/* 2. –егистраци€ класса окна */


	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход



				  /* 3. —оздание окна */


				  // создаетс€ окно и переменной hWnd присваиваетс€ дескриптор окна
	hWnd = CreateWindowEx(
		0, // расширенный стиль окна
		szClassWindow, // им€ класса окна
		TEXT("Push RETURN/ESC to start/stop"), // заголовок окна
							   /* «аголовок, рамка, позвол€юща€ мен€ть размеры, системное меню,
							   кнопки развЄртывани€ и свЄртывани€ окна */
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT, // х-координата левого верхнего угла окна
		CW_USEDEFAULT, // y-координата левого верхнего угла окна
		350, // ширина окна
		100, // высота окна
		NULL, // дескриптор родительского окна
		NULL, // дескриптор меню окна
		hInst, // идентификатор приложени€, создавшего окно
		NULL); // указатель на область данных приложени€



			   /* 4. ќтображение окна */


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна


	HWND calcHWnd = FindWindow(TEXT("CalcFrame"), TEXT("Calculator")); // получим дескриптор " алькул€тора"


																	   /* 5. «апуск цикла обработки сообщений */


																	   // получение очередного сообщени€ из очереди сообщений
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg); // трансл€ци€ сообщени€
		DispatchMessage(&lpMsg); // диспетчеризаци€ сообщений
	}
	return lpMsg.wParam;
}





LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	
	static HWND calcHWnd;
	if(!calcHWnd) calcHWnd = FindWindow(TEXT("CalcFrame"), TEXT("Calculator")); // получим дескриптор " алькул€тора"


	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);


	static int posX = 0;
	static int posY = 0;



	TCHAR str[50];
	switch (uMessage)
	{


	case WM_TIMER:


		if (posX <= screenX - 300 && posY == 0) {
			MoveWindow(calcHWnd, posX, 0, 300, 300, 1);
			posX += 10;
		}
		if (posX == screenX - 300 && posY <= screenY - 300) {
			MoveWindow(calcHWnd, posX, posY, 300, 300, 1);
			posY += 10;
		}
		if (posY == screenY - 300 && posX >= 0) {
			MoveWindow(calcHWnd, posX, posY, 300, 300, 1);
			posX -= 10;
		}
		if (posX == 0 && posY >= 0) {
			MoveWindow(calcHWnd, posX, posY, 300, 300, 1);
			posY -= 10;
		}




		break;


	case WM_KEYDOWN:

		if (!calcHWnd) MessageBox(hWnd, TEXT("Open calculator please!"), TEXT("Error!"), MB_OK | MB_ICONWARNING);
		else
		if (wParam == VK_RETURN) {

			SetWindowText(calcHWnd, TEXT("BLA BLA BLAA"));

			SetTimer(hWnd, 1, 100, 0);
		}

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