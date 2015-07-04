#include <iostream>
#include <string>


using namespace std;


struct Company		 {


	// Поля компании
	string name;
	string owner;
	int phone;
	string line;







	Company generateCompany() {
		Company newCompany;

		// Данные для генерации рандомной компании
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
			"Типография",
			"Хлебзавод",
			"Автозавод",
			"Парикмахерская",
			"Склад",
			"Кафе",
			"Бар",
			"Ресторан",
			"Магазин",
			"Прачечная",
			"Школа",
			"Интернет провайдер",
			"Грузоперевозки",
			"Тур оператор",
			"Спортивное снаряжение",
			"Спорт зал",
			"Молокозавод",
			"Ремонт велосипедов",
			"Ветеринарная клиника",
			"Ритуальные услуги"


		};

		newCompany.name = (brandParts[rand() % 10]) + (brandParts[rand() % 10]) + (brandParts[rand() % 10]);
		newCompany.owner = names[rand() % 20] + lastNames[rand() % 20];
		newCompany.phone = rand() * 10000 + rand();
		newCompany.line = lines[rand() % 20];



		return newCompany;
	}

	void show() {
		cout << "Название компании: 	" << name << endl;
		cout << "Владалец: 		" << owner << endl;
		cout << "Род деятельности: 	" << line << endl;
		cout << "Контактный телефон: 	+" << phone << endl << endl;;


	}




};


struct Catalog {

	Company* company;
	size_t size;

	Catalog() :size(20) {
		Company* newCatalog = new Company[20];


		for (int i = 0;i < 20; i++) {
			Company a = a.generateCompany();
			newCatalog[i] = a;
		}

		company = newCatalog;

	}

	void show() {
		for (int i = 0; i < size; i++) {
			company[i].show();
		}
	}




};


int main() {
	setlocale(0, "rus");



	Catalog a;

	a.show();

}