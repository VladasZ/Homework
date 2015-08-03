#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;




int main(){

	//��������� ������ ������� 10 ���������� ����� ����� � ������� ��� � �������� �����.
	vector <int> square(10);

	for (int i = 0; i < square.size(); i++){
		int a = rand() % 10;
		square[i] = a*a;
	}

	for (int a : square){
		cout << a << endl;
	}
	cout << endl;
	//��������� ���������� ������ �������� ��������� � �������� ��� � �������� �����.

	map <string, int> table;
	// ��������� map
	for (int i = 1; i < 10; i++){
		for (int j = 1; j < 10; j++){
			string a;
			a.insert(0, to_string(i));
			a.push_back('*');
			a.insert(a.size(), to_string(j));
			a.insert(a.size(), " = ");
			table.insert(pair<string, int>(a, i*j));
						
		}
	}
	// ������� �� �����
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		static int i = 0;
		cout << (*it).first << (*it).second << ", ";
		if (!(i++ % 5)) cout << endl;
	}




	return 0;
}