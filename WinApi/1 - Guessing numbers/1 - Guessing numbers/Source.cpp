#include <Windows.h>
//#include <tchar.h>
#include <string>

using namespace std;


int guess(int number) {
	
	static int iteration = 1;
	static int try_ = 0;
	++try_;

	string message = "Is your number bigger than  ";
	message.insert(message.size(), (to_string(number)));
	message.insert(message.size(),"?");


	iteration *= 2;

	int answer = (MessageBox(0, TEXT(message.c_str()), TEXT("Guessing numbers"), MB_YESNOCANCEL));

	

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
		message.insert(0,"Guessing your number takes ");
		message.insert(message.size(), (to_string(try_)));
		message.insert(message.size(), " attempts.");
		(MessageBox(0, TEXT(message.c_str()), TEXT("Guessing numbers"), MB_OK));
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