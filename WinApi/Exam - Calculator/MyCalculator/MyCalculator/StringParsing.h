#pragma once
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

struct Borders {
	int left, right;
	string expr;
	Borders(int left, int right) : left(left), right(right) {}
	Borders() :left(0), right(0) {}

};


class StringParsing
{
	TCHAR w_text[50];

	typedef bool(*dllFunc)(const TCHAR[]);
	dllFunc checkBrackets;
	HINSTANCE hLib;

	inline bool isSymbol(int i, string expr);
	inline bool isHook(int i, string expr);
	inline bool isSign(int i, string expr);
	inline bool isDigit(int i, string expr);
	inline bool isLetter(int i, string expr);
	


	int findNextHook(int pos, string expr);

	int findPrevHook(int pos, string expr);

	int findNextSymbol(int pos, string expr);

	int findPrevSymbol(int pos, string expr);

	int findPrimaryExpression(string expr);

	
	string binaryCalculation(string expr);


	Borders findBinaryExpression(string expr);

	void replaceBinaryExpression(string *expr, Borders binary);


	
	char text[50];


public:
	int calculate(string expr);
	

	StringParsing();
	~StringParsing();
};

