#include <iostream>
#include <string>

using namespace std;

int number(char* n){
	
	long long a = 0;

	for (int i = 0; i < strlen(n); i++){
		if (n[i] > 58 || n[i] < 48) throw "only digits allowed!!";
	}

	for (int i = 0; i < strlen(n); i++){
		a += ((int)n[strlen(n) - i - 1] - 48)*pow(10, i);
	}

	if (a > INT_MAX) throw "int owerflow!";
	
	return a;
}



int main(){

	try { cout << number("7687") << endl; }
	catch (char* a){ cout << "error code: " << a << endl; }

	try{ cout << number("7jhgj687") << endl; }
	catch (char* a){ cout << "error code: " << a << endl; }

	try{ cout << number("74324324345687") << endl; }
	catch (char* a){ cout << "error code: " << a << endl; }
	

	



	return 0;
}