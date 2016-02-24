#include <iostream>
#include <list>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class TextElem;

typedef shared_ptr<TextElem> ElemPtr;
#define newComposite  make_shared<CompositeText>()
#define SPACE make_shared<Letter>(' ')



class TextElem {
public:
	virtual void draw() = 0;
	virtual void add(const ElemPtr) = 0;
	virtual void remove(const ElemPtr) = 0;
	virtual void clear() = 0;

};


class Letter : public TextElem {
	char letter;
public:
	Letter(const char& letter) : letter(letter) {}
	void draw() {
		cout << letter;
	}

	void add(const ElemPtr) {
		cout << "Error. Can't add another element to the class letter" << endl;
	}

	void remove(const ElemPtr) {
		cout << "Error. Can't delete element from the class letter" << endl;
	}
	void clear() {
		cout << "Error. Can't erase a letter" << endl;
	}

};

class CompositeText : public TextElem {

	list<ElemPtr> word;
public:
	void draw() {
		for (auto a : word) {
			a->draw();
		}
	}

	void add(const ElemPtr _word) {
		word.push_back(_word);
	}

	void remove(const ElemPtr _word) {
		word.remove(_word);
	}

	void clear() {
		word.clear();
	}
};


namespace FileInterface {
	//public:
	string path = "txt.txt";
	string word;

	vector<ElemPtr> words;
	vector<ElemPtr> sentences;

	ElemPtr ElWord;
	ElemPtr sentence;
	ElemPtr Text = newComposite;




	void readText() {
		ifstream fin(path);

		while (!fin.eof()) {
			fin >> word;

			ElWord = newComposite;

			for (auto a : word) {// Creating words from letters
				ElemPtr let = make_shared<Letter>(a);
				ElWord->add(let);
			}

			words.push_back(ElWord);// Saving words for creating sentences


			if (word.at(word.size() - 1) == '.') { // Creating new sentence when the last character of the word is a dot.

				sentence = newComposite;

				for (auto a : words) {
					sentence->add(a);
					sentence->add(SPACE);
				}

				Text->add(sentence);

				words.clear();
			}


		}


		fin.close();
	}







};


int main() {

	setlocale(LC_ALL, "rus");



	FileInterface::readText();


	FileInterface::Text->draw();




	return 0;
}