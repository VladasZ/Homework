#pragma once
#include <string>
#include <Windows.h>

using namespace std;

class StringParsing
{

	inline bool isSymbol(int i, string expr);
	inline bool isHook(int i, string expr);
	inline bool isSign(int i, string expr);

	int findNextHook(int pos, string expr);

	int findPrevHook(int pos, string expr);

	int findNextSymbol(int pos, string expr);

	int findPrevSymbol(int pos, string expr);

	//int findPrimaryExpression(string expr){
	//	for (int i = 0; i < expr.size(); i++){
	//		if (expr[i] == '*' || expr[i] == '/') return i;
	//	}
	//	return 0;
	//}

	//struct Borders{
	//	int left, right;
	//	string expr;
	//	Borders(int left, int right) : left(left), right(right){}
	//	Borders() :left(0), right(0){}
	//	void show(){
	//		cout << left << ' ' << right << endl;
	//	}
	//};

	//string binaryCalculation(string expr){
	//	//cout << expr << " = ";
	//	int res;
	//	int a, b, signPos;
	//	string str_a, str_b, str_res;
	//	for (int i = 0; i < expr.size(); i++){
	//		if ((expr[i] < '0' || expr[i] > '9'))// èùåì çíàê îòëè÷íûé îò öèôðû
	//		{
	//			signPos = i;
	//			for (int j = 0; j < signPos; j++){
	//				str_a.push_back(expr[j]);
	//			}
	//			for (int j = signPos + 1; j < expr.size(); j++){
	//				str_b.push_back(expr[j]);
	//			}
	//		}
	//	}
	//	// êîíâåðòèðóåì ñòðîêè â int
	//	a = stoi(str_a);
	//	b = stoi(str_b);

	//	// âûïîëíÿåì âû÷èñëåíèå â çàâèñèìîñòè îò çíàêà

	//	switch (expr[signPos])
	//	{
	//	case '+':
	//		res = a + b;
	//		break;
	//	case '-':
	//		res = a - b;
	//		break;
	//	case '*':
	//		res = a * b;
	//		break;
	//	case '/':
	//		res = a / b;
	//		break;
	//	default:
	//		break;
	//	}

	//	// êîòâåðòèðóåì int îáðàòíî â string
	//	str_res = to_string(res);
	//	return str_res;
	//}


	//Borders findBinaryExpression(string expr){

	//	Borders borders;


	//	for (int i = 0; i < expr.size(); i++)
	//	{
	//		if (isSymbol(i, expr))
	//		{
	//			if (isHook(i + 1, expr))
	//			{
	//				borders.left = i + 2;
	//				borders.right = findNextHook(i + 2, expr) - 1;
	//				break;
	//			}
	//			else if (isHook(i - 1, expr))
	//			{
	//				borders.right = i - 2;
	//				borders.left = findPrevHook(i - 2, expr) + 1;
	//				break;
	//			}
	//			else if (expr[i] == '*' || expr[i] == '/')
	//			{
	//				borders.left = findPrevSymbol(i, expr) + 1;
	//				borders.right = findNextSymbol(i, expr) - 1;
	//				break;
	//			}
	//			else if (expr[i] == '+' || expr[i] == '-')
	//			{
	//				if (findPrimaryExpression(expr)) continue;
	//				borders.left = findPrevSymbol(i, expr) + 1;
	//				borders.right = findNextSymbol(i, expr) - 1;
	//				//cout << "dripo" << endl;
	//				break;
	//			}
	//		}
	//	}



	//	for (int i = borders.left; i <= borders.right; i++){
	//		borders.expr.push_back(expr[i]);
	//	}

	//	return borders;

	//}

	//void replaceBinaryExpression(string *expr, Borders binary){

	//	int hooksDeleted = 0;
	//	//cout << *expr << endl;



	//	//óäàëÿåì áèíàðíîå âûðàæåíèå 

	//	if (binary.left == 0)
	//	{
	//		expr->erase(binary.left, binary.right - binary.left + 1);
	//	}
	//	else
	//	{
	//		expr->erase(binary.left, binary.right - binary.left + 1);
	//	}

	//	//cout << *expr << endl;


	//	// óäàëÿåì ñêîáêè åñëè îíè åñòü
	//	if (binary.left != 0){
	//		if (expr->at(binary.left - 1) == '('){
	//			expr->erase(binary.left - 1, 2);
	//			hooksDeleted++;
	//		}
	//	}
	//	//cout << *expr << endl;

	//	// âñòàâëÿåì ðåçóëüòàò âè÷èñëåíèÿ íà ìåñòî âûðàæåíèÿ

	//	expr->insert(binary.left - hooksDeleted, binaryCalculation(binary.expr));

	//	//cout << *expr << endl;




	//}


	//int calculate(string expr){
	//	int result = 0;
	//	// Ïðîâåðÿåì ïðàâèëüíîñòü ðàññòàíîâêè ñêîáîê
	//	Stack a = expr;
	//	if (!a.checkHooks())
	//	{
	//		std::cout << "Hooks error!" << endl;
	//		return 0;
	//	}

	//	// åñëè â ñòðîêå òîëüêî îäèí çíàê ñðàçó âîçâðàùàåì îòâåò
	//	int signCount = 0;
	//	for (int i = 0; i < expr.size(); i++){
	//		if (expr[i]<'0' || expr[i]>'9') signCount++;
	//	}



	//	if (signCount == 1){
	//		expr = binaryCalculation(expr);
	//		return stoi(expr);
	//	}


	//	Borders binary = findBinaryExpression(expr);

	//	replaceBinaryExpression(&expr, binary);


	//	return calculate(expr);

	//}




public:





	StringParsing();
	~StringParsing();
};

