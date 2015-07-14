#include <iostream>

using namespace std;

class List{
public:
	virtual void push(int n) = 0;
	virtual int pull() = 0;
	virtual void show() = 0;

};



struct Node{
	int n;
	Node* next;
	Node(int n, Node* next) : n(n), next(next){}
};

class Queue : public List{
	Node* last = nullptr;

	virtual void push(int i){

		if (last == nullptr)
		{
			last = new Node(i, nullptr);
		}

		else
		{
			Node* newNode = new Node(i, last);
			last = newNode;
		}


	}

	virtual int pull(){
		Node* temp = last;
		last = last->next;
		return temp->n;	
	}

	virtual void show(){
		
		Node* current = last;

		while (current != nullptr){
			
			cout << current->n << endl;
			current = current->next;
		}

	}



};

class Stack : public List{
	Node* last = nullptr;

	virtual void push(int i){

		if (last == nullptr)
		{
			last = new Node(i, nullptr);
		}

		else
		{
			Node* newNode = new Node(i, last);
			last = newNode;
		}


	}

	virtual int pull(){
		Node* temp = last;
		last = last->next;
		return temp->n;
	}

	virtual void show(){

		Node* current = last;

		while (current != nullptr){

			cout << current->n << endl;
			current = current->next;
		}

	}



};