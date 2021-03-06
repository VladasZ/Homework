#include <iostream>
#include <fstream>
#include <string>
#define MORE 1
#define LESS 0

using namespace std;


struct Base {

	struct Node {
		// ���� ������
		int n;
		size_t violationCount = 1;
		string violation[10];

		// ���� ��� �������� ������
		
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
		
			if (n == -1) cout << "����� �� ������" << endl;
			else {
				cout << "����� ������: " << n << endl;
				cout << "���������: " << endl;
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
	Base(int size) {
		for (int i = 0; i < size;i++) {
			addPenalty(generateCar());
		
		}
	}

	Node* generateCar() {
	
		int n = rand() % 10000;


		string viol[10] = { "���������� ��������",
			"������ �� ������� ����",
			"�������� � ������������ �����",
			"������ ����� 2 ��������",
			"����� � ������������ �����" ,
			"�������� ��������� ��������" ,
			"���������� � ��������� ������������ ���������" ,
			"��������� ������ ����������" ,
			"������� � ������������ �����" ,
			"�� ���������� ������" };


		Node* car = new Node(n, viol[rand() % 10]);

		int violCount = rand() % 4;

		for (int i = 0;i < violCount;i++) {
			car->addViolation(viol[rand() % 10]);
		}

		return car;
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

					if (current->n == car->n) {
						static int i;
					
						while (current->n == car->n) {
							car = generateCar();
					
						}
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
		int f = 0;
		
		
		while (++f) {
			if (sorted[f].n > from)
			{
				break;
			}
		}
		int t = f;
		while (++t) {
			if (sorted[t].n > to)
			{
				t;
				break;
			}
		}

		while (f < t) {
			sorted[f++].show();
		}

	}

	

	void save(string path) {
		ofstream fout(path);
		for (int i = 0;i < size;i++) {
			fout << "����� ������: " << sorted[i].n << endl;
			fout << "���������: " << endl;
			for (int j = 0; j <= sorted[i].violationCount;j++) {
				fout << sorted[i].violation[j] << endl;
			}
			fout << endl;
		}

	}

	void saveInRange(string path, int from, int to) {
		ofstream fout(path);

		int f = 0;


		while (++f) {
			if (sorted[f].n > from)
			{
				break;
			}
		}
		int t = f;
		while (++t) {
			if (sorted[t].n > to)
			{
				break;
			}
		}

		while (f < t) {

			
				
				fout << "����� ������: " << sorted[f].n << endl;
				fout << "���������: " << endl;
				for (int j = 0; j <= sorted[f].violationCount;j++) {
					fout << sorted[f].violation[j] << endl;
				}
				fout << endl;
				f++;
			
		}

	}


};

int main() {
	setlocale(LC_ALL, "rus");

	Base a = 1000;
	


	



	//a.show(a.root);

	a.sort();
	//a.showSort();

	a.showInRange(4000, 4500);
	a.save("c:\\base.txt");
	a.saveInRange("c:\\in range 4000 5000.txt", 4000, 5000);
	return 0;
}