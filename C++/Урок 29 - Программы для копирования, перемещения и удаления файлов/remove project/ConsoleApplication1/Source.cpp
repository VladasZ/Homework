#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc == 1) cout << "��� ����������" << endl;
	if (argc > 1) 
	{
		
		if (remove(argv[1]) == -1) {
			cout << "���� �� ������" << endl;
		}
		else {
			cout << "���� :\n" << argv[1] << "\n ������� ������ \n";
		}
		
	

	
	}

	

	system("pause");
	
	
	return 0;
}