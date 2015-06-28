#include <iostream>
#include <string>
#define MORE 1
#define LESS 0

using namespace std;


struct Base {

	struct Node {
		// поля данных
		int n;
		size_t violationCount = 1;
		string violation[10];

		// поля для создания дерева
		
		Node* left;
		Node* right;
		Node(){}
		Node(int n, string violation) : n(n), left(nullptr), right(nullptr)
		{
			this->violation[0] = violation;
		}


		void addViolation(string violation) {
			this->violation[violationCount++] = violation;

		}
		void show() {

			if (n == -1) cout << "Номер не найден" << endl;
			else {
				cout << "Номер машины: " << n << endl;
				cout << "Нарушения: " << endl;

				for (int i = 0; i <= violationCount;i++) {
					cout << violation[i] << endl;
				}
				cout << endl;
			}
		}
	};

	size_t size = 0;
	Node* root = nullptr;

	Node* sorted;
	Base() {
		for (int i = 0; i < 20;i++) {
			addPenalty(generateCar());
		}
	}


	void addToSort(Node* node) {
		static int i = 0;
		if (node != nullptr) {
			addToSort(node->left);
			sorted[i] = *node;
			i++;
			addToSort(node->right);
		}

	}

	void sort() {
		sorted = new Node[size];
		addToSort(root);
	}

	void showSort() {
		for (int i = 0;i < size;i++) {
			cout << sorted[i].n << endl;
		}
	}
	Node* generateCar() {
		int n = rand() % 10000;
		
		string viol[10] = { "Превышение скорости",
		"Проезд на красный свет",
		"Парковка в неположенном месте",
			"Проезд через 2 сплошные",
			"Обгон в неположенном месте" ,
			"Создание аварийной ситуации" ,
			"Управление в состоянии алкогольного опьянения" ,
			"Нарушение правил буксировки" ,
			"Стоянка в неположенном месте" ,
			"Не пристегнут ремень" };


		Node* car = new Node(n, viol[rand() % 10]);

		int violCount = rand() % 4;

		for (int i=0;i < violCount;i++) {
			car->addViolation(viol[rand() % 10]);
		}

		return car;
	}

	void addPenalty(int n, string violation) {
		Node* newNode = new Node(n, violation);
		if (root == nullptr) 
		{
			root = newNode;
			size++;
		}
		else {

			Node* current = root;
			Node* prev = current;
			
			
			int compare = 0;

			while (current != nullptr) {
			
				prev = current;
				if (current->n == n)
				{
					current->addViolation(violation);
				}




				if (current->n < n)
				{
					compare = MORE;
					current = current->right;
				}

				else
				{
					compare = LESS;
					current = current->left;
				}

			}

			current = newNode;

			if (compare == MORE) {
				prev->right = current;
			}
			else {
				prev->left = current;
			}
			size++;
		}
	}
	void addPenalty(Node* car) {
		Node* newNode = car;
		if (root == nullptr)
		{
			root = newNode;
			size++;

		}
		else {

			Node* current = root;
			Node* prev = current;


			int compare = 0;

			while (current != nullptr) {

				prev = current;
				
				if (current->n == car->n)
				{
					current = car;
				}




				if (current->n < car->n)
				{
					compare = MORE;
					current = current->right;
				}

				else
				{
					compare = LESS;
					current = current->left;
				}

			}

			current = newNode;

			if (compare == MORE) {
				prev->right = current;
			}
			else {
				prev->left = current;
			}
			size++;
		}
	}
	void show(Node* node) {
		if (node != nullptr) {
			show(node->left);
			node->show();
			show(node->right);
		}

	}
	Node& operator [](int name) {
		Node* current = root;

		while (current->n != name) {

			if (current->n < name) {
				current = current->right;
			}
			else {
				current = current->left;
			}
			if (current == nullptr) {
				
				current = new Node(-1, " ");
				return *current;
			}
		}
		
		return *current;


	}


	void showInRange(int from, int to) {
		Node* current = root;
		
		

		while (current->right->n < from) {
			cout << current->n << endl;
			if (current->n < from) current = current->right;
			else current = current->left;
		}
		cout << endl;
		cout << current->n << endl;
	}


};

int main() {
	setlocale(LC_ALL, "rus");

	Base a;
	


	



	a.show(a.root);
	a[1234].show();
	a.sort();
	a.showSort();
	cout << a.size << endl;
	//a.showInRange(4000, 0);
	return 0;
}