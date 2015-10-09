#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <cstdlib>

using namespace std;

enum Button { Esc = 27, Backspace = 8, Enter = 13 };

class Memento {
	vector<string> memory;
public:

	void saveState();
	void cancel();
}memento;


class TextEditor {
public:
	string data;


	TextEditor& type(char letter) {


		if (letter == Esc) {

			memento.cancel();
			return *this;
		}


		memento.saveState();

		if (letter == Backspace) {
			cout << (char)Backspace << ' ' << (char)Backspace;
			if (data.size()) data.pop_back();

			return *this;
		}

		if (letter == Enter) {
			return *this;
		}



		cout << letter;
		data.push_back(letter);
		return *this;
	}

	void redraw() {
		system("cls");
		cout << data;
	}




}textEditor;



void Memento::saveState() {
	memory.push_back(textEditor.data.c_str());
}

void Memento::cancel() {

	textEditor.data.clear();

	if (memory.size()) {
		textEditor.data = memory[memory.size() - 1].c_str();
		memory.pop_back();
	}
	textEditor.redraw();
}



int main() {



	while (7) {
		textEditor.type(getch());

	}


	return 0;
}