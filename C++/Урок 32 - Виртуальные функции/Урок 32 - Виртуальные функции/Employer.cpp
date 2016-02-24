#include <iostream>

using namespace std;


class Employer{
public:
	virtual void print() = 0;	
};



class President : public Employer{
	virtual void print(){
		cout << "I am the President" << endl;
	}
};

class Manager : public Employer{
	virtual void print(){
		cout << "I am the Manager" << endl;
	}
};

class Worker : public Employer{
	virtual void print(){
		cout << "I am the Worker" << endl;
	}
};