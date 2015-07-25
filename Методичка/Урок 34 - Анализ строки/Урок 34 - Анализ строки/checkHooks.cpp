#include <iostream>
using namespace std;


class Stack{
	string strng;
	int size = 0;
public:



	Stack(string string) : strng(string){}

	/*Ћогика проверки:
	если (количество открытых и закрытых скобок одинаково) и
	если (перва€ скобка не закрыта€) и
	если (последн€€ скобка не открыта€)
	скобки расставлены правильно
	*/
	bool checkOneTypeOfHooks(char openHook, char closeHook){
		int open = 0;
		int close = 0;
		char firstHook = 0;
		char lastHook = 0;

		for (int i = 0; i <= strng.size(); i++) {


			if (strng[i] == openHook){

				if (!firstHook) {
					firstHook = openHook;
				}

				lastHook = openHook;

				open++;
			}



			if (strng[i] == closeHook){

				if (!firstHook) {
					firstHook = closeHook;
				}

				lastHook = closeHook;

				close++;
			}





		}


		if (open == close &&
			firstHook != closeHook   &&
			lastHook != openHook)
		{
			return true;
		}
		//cout << "Wrong " << openHook << closeHook << endl;
		return false;
	}


	bool checkHooks(){

		if (checkOneTypeOfHooks('(', ')') &&
			checkOneTypeOfHooks('[', ']') &&
			checkOneTypeOfHooks('{', '}'))

		{
			return true;
		}

		return false;
	}


	void display(){
		for (int i = 0; i <= strng.size(); i++){
			cout << strng[i];
		}
		cout << endl;
	}


};


