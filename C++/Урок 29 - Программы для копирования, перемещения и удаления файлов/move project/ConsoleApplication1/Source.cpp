#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc == 1) cout << "Нет параметров" << endl;
	if (argc == 2) cout << "Для переноса файла нужно 2 параметра" << endl;
	if (argc > 2)
	{
		
		if (rename(argv[1], argv[2]) == -1) {
			cout << "Файл не найден" << endl;
		}
		else {
			cout << "Файл :\n" << argv[1] << "\n успешно перенесен в директорию: \n" << argv[2];
		}
		
	

	
	}

	

	system("pause");
	
	
	return 0;
}