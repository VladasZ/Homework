#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc == 1) cout << "��� ����������" << endl;
	if (argc == 2) cout << "��� �������� ����� ����� 2 ���������" << endl;
	if (argc > 2)
	{
		
		if (rename(argv[1], argv[2]) == -1) {
			cout << "���� �� ������" << endl;
		}
		else {
			cout << "���� :\n" << argv[1] << "\n ������� ��������� � ����������: \n" << argv[2];
		}
		
	

	
	}

	

	system("pause");
	
	
	return 0;
}