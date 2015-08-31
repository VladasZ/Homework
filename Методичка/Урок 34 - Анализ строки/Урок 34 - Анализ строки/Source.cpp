#include <iostream>
#include <string>   
#include "checkHooks.cpp"


using namespace std;



inline bool isSymbol(int i, string expr){
	return (expr[i]<'0' || expr[i]>'9') && (expr[i] != '(' && expr[i] != ')');
}

inline bool isHook(int i, string expr){
	return expr[i] == '(' || expr[i] == ')';
}

inline bool isSign(int i, string expr){
	return isSymbol(i, expr) || isHook(i, expr);
}

int findNextHook(int pos, string expr){
	for (int i = pos+1; i < expr.size(); i++)
	{
		if (isHook(i, expr))
		{
			return i;
		}
	}

	return 0;
}

int findPrevHook(int pos, string expr){
	for (int i = pos - 1; i > 0; i--)
	{
		if (isHook(i, expr))
		{
			return i;
		}
	}

	return 0;
}

int findNextSymbol(int pos, string expr){
	for (int i = pos + 1; i < expr.size(); i++)
	{
		if (isSymbol(i, expr))
		{
			return i;
		}
	}

	return expr.size();
}

int findPrevSymbol(int pos, string expr){
	for (int i = pos - 1; i > 0; i--)
	{
		if (isSymbol(i, expr))
		{
			return i;
		}
	}

	return -1;
}

int findPrimaryExpression(string expr){
	for (int i = 0; i < expr.size(); i++){
		if (expr[i] == '*' || expr[i] == '/') return i;
	}
	return 0;
}

struct Borders{
	int left, right;
	string expr;
	Borders(int left, int right) : left(left), right(right){}
	Borders() :left(0), right(0){}
	void show(){
		cout << left << ' ' << right << endl;
	}
};

string binaryCalculation(string expr){
	//cout << expr << " = ";
	int res;
	int a, b, signPos; 
	string str_a, str_b, str_res;
	for (int i = 0; i < expr.size(); i++){
		if ((expr[i] < '0' || expr[i] > '9'))// ищем знак отличный от цифры
		{
			signPos = i;
			for (int j = 0; j < signPos; j++){
				str_a.push_back(expr[j]);
			}
			for (int j = signPos+1; j < expr.size(); j++){
				str_b.push_back(expr[j]);
			}
		}
	}
	// конвертируем строки в int
	a = stoi(str_a);
	b = stoi(str_b);

	// выполняем вычисление в зависимости от знака

	switch (expr[signPos])
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = a / b;
		break;
	default:
		break;
	}
	
	// котвертируем int обратно в string
	str_res = to_string(res);
	return str_res;
}


Borders findBinaryExpression(string expr){
	
	Borders borders;


	for (int i = 0; i < expr.size(); i++)
	{
		if (isSymbol(i, expr))
		{
			if (isHook(i + 1, expr))
			{
				borders.left = i+2;
				borders.right = findNextHook(i+2, expr) - 1;
				break;
			}
			else if (isHook(i - 1, expr))
			{
				borders.right = i - 2;
				borders.left = findPrevHook(i - 2, expr) + 1;
				break;
			}
			else if (expr[i] == '*' || expr[i] == '/')
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
				//cout << "dripo" << endl;
				break;
			}
		}
	}

	

	for (int i = borders.left; i <= borders.right; i++){
		borders.expr.push_back(expr[i]);
	}

	return borders;
	
}

void replaceBinaryExpression(string *expr, Borders binary){

	int hooksDeleted = 0;
	//cout << *expr << endl;

	

	//удаляем бинарное выражение 

	if (binary.left == 0)
	{
		expr->erase(binary.left, binary.right - binary.left + 1);
	}
	else
	{
		expr->erase(binary.left, binary.right - binary.left + 1);
	}

	//cout << *expr << endl;


	// удаляем скобки если они есть
	if (binary.left != 0){
		if (expr->at(binary.left - 1) == '('){
			expr->erase(binary.left - 1, 2);
			hooksDeleted++;
		}
	}
	//cout << *expr << endl;

	// вставляем результат вичисления на место выражения

	expr->insert(binary.left - hooksDeleted, binaryCalculation(binary.expr));

	//cout << *expr << endl;

	

	
}


int calculate(string expr){
	int result = 0;
	// Проверяем правильность расстановки скобок
	Stack a = expr;
	if (!a.checkHooks())
	{
		std::cout << "Hooks error!" << endl;
		return 0;
	}

	// если в строке только один знак сразу возвращаем ответ
	int signCount = 0;
	for (int i = 0; i < expr.size(); i++){
		if (expr[i]<'0' || expr[i]>'9') signCount++;
	}


	
	if (signCount == 1){
		expr = binaryCalculation(expr);
		return stoi(expr);
	}


	Borders binary = findBinaryExpression(expr);

	replaceBinaryExpression(&expr, binary);


	return calculate(expr);

}

int main(){
	
	string a = "50-500*17000";
	
	cout << calculate(a) << endl;

}