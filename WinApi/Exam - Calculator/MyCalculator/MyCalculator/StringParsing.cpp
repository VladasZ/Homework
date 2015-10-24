#include "StringParsing.h"




inline bool StringParsing::isSymbol(int i, string expr) {
	return (expr[i]<'0' || expr[i]>'9') && (expr[i] != '(' && expr[i] != ')');
}

inline bool StringParsing::isHook(int i, string expr) {
	return expr[i] == '(' || expr[i] == ')';
}

inline bool StringParsing::isSign(int i, string expr) {
	if (isSign(i + 1, expr)) throw "Invalid input, 2 operators";
	return isSymbol(i, expr) || isHook(i, expr);
}

inline bool StringParsing::isDigit(int i, string expr) {
	return (expr[i]<'0' || expr[i]>'9');
}

inline bool StringParsing::isLetter(int i, string expr)
{
	return  ((expr[i] > 'a' && expr[i]<'z') ||
		(expr[i]>'A' && expr[i] < 'Z'));
}


int StringParsing::findNextHook(int pos, string expr) {
	for (int i = pos + 1; i < expr.size(); i++)
	{
		if (isHook(i, expr))
		{
			return i;
		}
	}

	return 0;
}

int StringParsing::findPrevHook(int pos, string expr) {
	for (int i = pos - 1; i > 0; i--)
	{
		if (isHook(i, expr))
		{
			return i;
		}
	}

	return 0;
}

int StringParsing::findNextSymbol(int pos, string expr) {
	for (int i = pos + 1; i < expr.size(); i++)
	{
		if (isSymbol(i, expr))
		{
			return i;
		}
	}

	return expr.size();
}

int StringParsing::findPrevSymbol(int pos, string expr) {
	for (int i = pos - 1; i > 0; i--)
	{
		if (isSymbol(i, expr))
		{
			return i;
		}
	}

	return -1;
}

int StringParsing::findPrimaryExpression(string expr) {
	for (int i = 1; i < expr.size(); i++) {
		if ((expr[i] == 'x' || expr[i] == '*' || expr[i] == '/') &&
			expr[i+1] != '(' && expr[i-1] != ')'
			) return i;
	}
	return 0;
}


string StringParsing::binaryCalculation(string expr) {


	for (int i = 0; i <= expr.size(); ++i) {

		if (i == expr.size()) {
			expr.clear();
			return expr;
		}

		if (isDigit(i, expr)) break;
	}

	int res;
	int a, b, signPos;
	string str_a, str_b, str_res;
	for (int i = 0; i < expr.size(); i++) {
		if ((expr[i] < '0' || expr[i] > '9'))
		{
			signPos = i;
			for (int j = 0; j < signPos; j++) {
				str_a.push_back(expr[j]);
			}
			for (int j = signPos + 1; j < expr.size(); j++) {
				str_b.push_back(expr[j]);
			}
		}
	}
	a = stoi(str_a);
	b = stoi(str_b);


	switch (expr[signPos])
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case 'x':case'*':
		res = a * b;
		break;
	case '/':
		if (!b) throw L"Divided by zero!";
		res = a / b;
		break;
	default:
		break;
	}

	str_res = to_string(res);
	return str_res;
}


Borders StringParsing::findBinaryExpression(string expr) {

	Borders borders;


	for (int i = 0; i < expr.size(); i++)
	{
		if (isSymbol(i, expr))
		{
			if (isHook(i + 1, expr))
			{
				borders.left = i + 2;
				borders.right = findNextHook(i + 1, expr) - 1;//2
				break;
			}
			else if (isHook(i - 1, expr))
			{
				borders.right = i - 2;
				borders.left = findPrevHook(i - 1, expr) + 1;//2
				break;
			}
			else if (expr[i] == 'x' || expr[i] == '*' || expr[i] == '/')
			{
				borders.left = findPrevSymbol(i, expr) + 1;
				borders.right = findNextSymbol(i, expr) - 1;
				break;
			}
			else if (expr[i] == '+' || expr[i] == '-')
			{
				if (findPrimaryExpression(expr)) continue;
				borders.left = findPrevSymbol(i, expr) + 1;
				borders.right = findNextSymbol(i, expr) - 1;
				
				break;
			}
		}
	}



	for (int i = borders.left; i <= borders.right; i++) {
		borders.expr.push_back(expr[i]);
	}

	return borders;

}

void StringParsing::replaceBinaryExpression(string *expr, Borders binary) {

	int hooksDeleted = 0;




	if (binary.left == 0)
	{
		expr->erase(binary.left, binary.right - binary.left + 1);
	}
	else
	{
		expr->erase(binary.left, binary.right - binary.left + 1);
	}



	if (binary.left != 0) {
		if (expr->at(binary.left - 1) == '(') {
			expr->erase(binary.left - 1, 2);
			hooksDeleted++;
		}
	}


	expr->insert(binary.left - hooksDeleted, binaryCalculation(binary.expr));





}


int StringParsing::calculate(string expr) {

	if (!expr.size()) throw(L"Write something");

	for (int i = 0; i < expr.size(); ++i) {
		if (isLetter(i, expr)) throw (L"Invalid expression");
	}

	if ((expr.back() < '0' || expr.back() > '9') &&
		expr.back() != '(' && expr.back() != ')') 
		throw(L"Enter last value");
	

	

	

	int result = 0;



	int signCount = 0;
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i]<'0' || expr[i]>'9') signCount++;
	}

	if (!signCount) return stoi(expr);

	if (signCount == 1) {
		expr = binaryCalculation(expr);
		return stoi(expr);
	}


	Borders binary = findBinaryExpression(expr);

	replaceBinaryExpression(&expr, binary);


	

	return calculate(expr);

}

StringParsing::StringParsing()
{
}


StringParsing::~StringParsing()
{
}


