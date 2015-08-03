#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Student{
public:
	string name;
	string lastName;
	int coure;
};

vector <Student> students;

void fillVector(){
	
	for (int i = 0; i < 20; i++){
		Student newStudent;
		for (int i = 0; i < 7; i++){
			newStudent.name.push_back(rand() % 26 + 65);
			newStudent.lastName.push_back(rand() % 26 + 65);
		}
		newStudent.coure = rand() % 4 + 1;
		students.push_back(newStudent);
	}
}

void printVector(){
	for (int i = 0; i < students.size(); i++){
		cout << students[i].name << ' '
			<< students[i].lastName << " course N"
			<< students[i].coure << endl;
	}
}

void sortVector(){
	for (int i = 0; i < students.size()-1; i++){
		for (int j = 0; j < students.size()-1; j++){
			if (students[j].name > students[j + 1].name){
				Student u = students[j];
				students[j] = students[j + 1];
				students[j + 1] = u;
			}
		}
	}
}


int main(){

	//«аполнить вектор длинной 10 квадратами целых чисел и вывести его в выходной поток.
	vector <int> square(10);

	for (int i = 0; i < square.size(); i++){
		int a = rand() % 10;
		square[i] = a*a;
	}

	for (int a : square){
		cout << a << endl;
	}
	cout << endl;
	//«аполнить двухмерный вектор таблицей умножени€ и выввести его в выходной поток.

	map <string, int> table;
	// заполн€ем map
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
	// выводим на экран
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		static int i = 0;
		cout << (*it).first << (*it).second << ", ";
		if (!(i++ % 5)) cout << endl;
	}


	fillVector();

	printVector();

	sortVector();
	
	cout << endl; 

	printVector();

	return 0;
}