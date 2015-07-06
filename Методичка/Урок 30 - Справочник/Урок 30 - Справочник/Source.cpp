#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct Company		 {


	// ���� ��������
	string name;
	string owner;
	string phone;
	string line;







	Company generateCompany() {
		Company newCompany;

		// ������ ��� ��������� ��������� ��������
		string brandParts[10] = {
			"Pro", "Top", "Elite", "Great", "Super", "Rich",
			"Ultra", "Business", "Company", "Concern"
		};
		string names[20] = {
			"Jacob" ,
			"Michael",
			"Joshua ",
			"Matthew",
			"Ethan" ,
			"Andrew",
			"Daniel",
			"William",
			"Joseph" ,
			"Christopher",
			"Anthony" ,
			"Ryan" ,
			"Nicholas",
			"David" ,
			"Alexander" ,
			"Tyler" ,
			"James" ,
			"John" ,
			"Dylan" ,
			"Nathan"
		};
		string lastNames[20]{


			" Abramson" , " Hoggarth" ,
			" Adamson" , " Holiday" ,
			" Adderiy" , " Holmes" ,
			" Addington" , " Howard" ,
			" Adrian" , " Jacobson" ,
			" Albertson" , " James" ,
			" Aldridge" , " Jeff" ,
			" Allford" , " Barnes",
			" Alsopp" , " Bishop",
			" Anderson" ,
			" Andrews"



		};
		string lines[20]{
			"����������",
			"���������",
			"���������",
			"��������������",
			"�����",
			"����",
			"���",
			"��������",
			"�������",
			"���������",
			"�����",
			"�������� ���������",
			"��������������",
			"��� ��������",
			"���������� ����������",
			"����� ���",
			"�����������",
			"������ �����������",
			"������������ �������",
			"���������� ������"


		};

		string numbers[10]{
			"1","2","3","4","5","6","7","8","9", "0" };

		newCompany.name = (brandParts[rand() % 10]) + (brandParts[rand() % 10]) + (brandParts[rand() % 10]);
		newCompany.owner = names[rand() % 20] + lastNames[rand() % 20];
		newCompany.phone = numbers[rand()%10] + numbers[rand() % 10] + numbers[rand() % 10] + numbers[rand() % 10] + numbers[rand() % 10] + numbers[rand() % 10] ;
		newCompany.line = lines[rand() % 20];



		return newCompany;
	}

	void show() {
		cout << "�������� ��������: 	" << name << endl;
		cout << "��������: 		" << owner << endl;
		cout << "��� ������������: 	" << line << endl;
		cout << "���������� �������: 	+" << phone << endl << endl;;


	}




};


struct Catalog {

	Company* company;
	size_t size = 0;
	string path = "banana";

	Catalog() :size(20) {
		Company* newCatalog = new Company[size];


		for (int i = 0;i < 20; i++) {
			Company a = a.generateCompany();
			newCatalog[i] = a;
		}

		company = newCatalog;

	}

	Catalog(string path) {

		ifstream fin(path, ios::in | ios::_Nocreate);

		string _size;
		getline(fin, _size);
		size = stoi(_size);

		company = new Company[size];

		for (int i = 0;i < size;i++) {
			getline(fin, company[i].name);
			getline(fin, company[i].owner);
			getline(fin, company[i].line);
			getline(fin, company[i].phone);
		}




		fin.close();


	}

	void show() {
		for (int i = 0; i < size; i++) {
			company[i].show();
		}
	}

	void save(string path) {
		this->path = path;

		ofstream fout(path, ios::out);
		
		fout << size << endl;

		for (int i = 0;i < size;i++) {
			fout << company[i].name << endl;
			fout << company[i].owner << endl;
			fout << company[i].line << endl;
			fout << company[i].phone << endl;


		}




		fout.close();


	}

	void add(string name, string owner, string phone, string line)
	{

		Company* newCompany = new Company;
		newCompany->name = name;
		newCompany->owner = owner;
		newCompany->phone = phone;
		newCompany->line = line;


		Company* temp = company;
		company = new Company[size + 1];

		for (int i = 0;i < size;i++) {
			company[i] = temp[i];
		}

		company[size++] = *newCompany;



		if (path != "banana") save(path);

	}


};


int main() {
	setlocale(0, "rus");


	// ������� ����� �������
	Catalog a;

	// ��������� ���
	a.save("c:\\txt.txt");
	
	// ��������� ����� ������� � ����������
	a.add("�� �������", "���� ������", "375299999999", "�����������");

	// ������� ����� ������� �� �����
	Catalog c ("c:\\txt.txt");


	// ������������� ����� �������
	c.show();

	
}




	
