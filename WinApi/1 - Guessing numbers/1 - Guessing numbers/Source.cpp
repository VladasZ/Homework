#define UNICODE

#include <Windows.h>
#include <tchar.h>
#include <string>

using namespace std;

#ifndef UNICODE  
typedef string String;
#define To_string to_string
#else
typedef wstring String;
#define To_string to_wstring

#endif

#define MDA 3;




int guess(const int& number) {
	
	static int iteration = 1;
	static int try_ = 0;
	++try_;

	String message = TEXT("Is your number bigger than  ");
	message.insert(message.size(), (To_string(number)));
	message.insert(message.size(),TEXT("?"));


	iteration *= 2;

	int answer = (MessageBox(0, (message.c_str()), TEXT("Guessing numbers"), MB_YESNOCANCEL));

	

	switch (answer)
	{
	case IDYES:
		if (iteration >= 32) guess(number + 1);
		else
		guess(number + 50 / iteration);
		break;
	case IDNO:
		if (iteration >= 32) guess(number - 1);
		else
		guess(number - 50 / iteration);
		break;
	case IDCANCEL:
		message.erase();
		message.insert(0,TEXT("Guessing your number took "));
		message.insert(message.size(), (To_string(try_)));
		message.insert(message.size(), TEXT(" attempts."));
		(MessageBox(0, (message.c_str()), TEXT("Guessing numbers"), MB_OK));
		iteration = 1;
		try_ = 0;
		return 0;
	default:
		break;
	}
		


	return -1;

}



INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine,
	int nCmdShow)
{
	(MessageBox(0, TEXT("Think of a number between 1 and 100\nClick cancel if you see your number."), TEXT("Guessing numbers"), MB_OK));


	while (1) {

		guess(50);
		if ((MessageBox(0, TEXT("Play again?"), TEXT("Guessing numbers"), MB_YESNO)) == IDNO) {
			break;
		}
	}


	return 0;
}
