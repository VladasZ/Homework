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

		Node(int n, string violation) : n(n), left(nullptr), right(nullptr)
		{
			this->violation[0] = violation;
		}


		void addViolation(string violation) {
			this->violation[violationCount++] = violation;

		}
		void show() {
			cout << "Номер машины: " << n << endl;
			cout << "Нарушения: " << endl;

			for (int i = 0; i <=violationCount;i++) {
				cout << violation[i] << endl;
			}
			cout << endl;
		}
		
	};

	Node* root = nullptr;

	

	void addPenalty(int n, string violation) {
		Node* newNode = new Node(n, violation);
		if (root == nullptr) 
		{
			root = newNode;
			
		}
		else {

			Node* current = root;
			Node* prev = current;
			int compare = 0;

			while (current != nullptr) {

				prev = current;

				if (current->n = n)
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
		}
	}







};

int main() {
	setlocale(LC_ALL, "rus");

	Base a;
	
	a.addPenalty(4565, "Дурны");
	a.addPenalty(3333, "Нямы");
	a.addPenalty(2222, "Сляпы");
	a.addPenalty(1111, "Сляпы");
	a.addPenalty(1234, "Сляпы");



	a.root->show();


	return 0;
}