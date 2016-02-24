#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc == 1) cout << "Нет параметров" << endl;
	if (argc > 1) 
	{
		
		if (remove(argv[1]) == -1) {
			cout << "Файл не найден" << endl;
		}
		else {
			cout << "Файл :\n" << argv[1] << "\n успешно удален \n";
		}
		
	

	
	}

	

	system("pause");
	
	
	return 0;
}