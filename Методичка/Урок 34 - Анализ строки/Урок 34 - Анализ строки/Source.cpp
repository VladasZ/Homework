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

	return 0;
}

int findPrevSymbol(int pos, string expr){
	for (int i = pos - 1; i > 0; i--)
	{
		if (isSymbol(i, expr))
		{
			return i;
		}
	}

	return 0;
}

struct Borders{
	int left, right;
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

	//cout << str_res;
	cout << str_res << " binary res" << endl;
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
			}
			else if (isHook(i - 1, expr))
			{
				borders.right = i - 2;
				borders.left = findPrevHook(i - 2, expr) + 1;
			}
			else if (expr[i] == '*' || expr[i] == '/')
			{

			}
		}
	}


	return borders;
	
}


int calculate(string expr){
	
	// Проверяем правильность расстановки скобок
	Stack a = expr;
	if (!a.checkHooks())
	{
		cout << "Hooks error!" << endl;
		return 0;
	}

	// если в строке только один знак сразу возвращаем ответ
	int signCount = 0;
	for (int i = 0; i < expr.size(); i++){
		if (expr[i]<'0' || expr[i]>'9') signCount++;
	}

	if (signCount == 1) return stoi(binaryCalculation(expr));

	



	int leftBorder = 0, rightBorder = 0;
	string binExpr;

	for (int i = 0; i < expr.size(); i++)
	{
		if (expr[i] == '*')
		{
			if (expr[i - 1] == ')')
			{
				cout << "first" << endl;
				// определяем границы бинарной оберации
				rightBorder = i - 2;
				for (int j = i - 2; j >= 0; j--)
				{
					if (expr[j] == '(')
					{
						leftBorder = j+1;
						break;
					}
				}
	
				// запоминаем бинарную операцию
				for (int j = leftBorder; j <= rightBorder; j++)
				{
					binExpr.push_back(expr[j]);
				}
				cout << binExpr << " 106" <<  endl;
				leftBorder--;
				rightBorder++;
				// удаляем бинарную операцию и скобки если они есть из строки
				if (expr[leftBorder-1] == '(') leftBorder--;
				if (expr[rightBorder] == ')') {
					rightBorder++; cout << "bla" << endl;
				}
			
				cout << leftBorder << ' ' << rightBorder << endl;
				expr.erase(leftBorder, rightBorder-leftBorder);

				cout << expr << endl;

				// вставляем на место бинарной операции ее значение

				expr.insert(leftBorder, binaryCalculation(binExpr));
				cout << expr << " 123" << endl;
				break;
			}

			else if (expr[i + 1] == '(')
			{
				cout << "second" << endl;
				// определяем границы бинарной оберации
				leftBorder = i + 2;
				for (int j = i + 2; j <= expr.size(); j++)
				{
					if (expr[j] == ')')
					{
						rightBorder = j - 1;
						break;
					}
				}
			
				// запоминаем бинарную операцию
				for (int j = leftBorder; j <= rightBorder; j++)
				{
					binExpr.push_back(expr[j]);
				}
				cout << binExpr << " 146" << endl;
				leftBorder--;
				rightBorder++;
				// удаляем бинарную операцию и скобки если они есть из строки
				if (expr[leftBorder - 1] == '(') leftBorder--;
				if (expr[rightBorder] == ')') {
					rightBorder++; cout << "bla" << endl;
				}

		
				expr.erase(leftBorder, rightBorder - leftBorder);

				cout << expr << endl;

				// вставляем на место бинарной операции ее значение

				expr.insert(leftBorder, binaryCalculation(binExpr));
				cout << expr << " 163" << endl;
				break;
			} 
			
			else{
				cout << "third" << endl;
				// определяем границы бинарной оберации
				
				for (int j = i - 2; j >= 0; j--)
				{
					if (expr[j]<'0' || expr[j]>'9')
					{
						leftBorder = j + 1;
						break;
					}
				}
				for (int j = i + 2; j <= expr.size(); j++)
				{
					if (expr[j]<'0' || expr[j]>'9')
					{
						rightBorder = j - 1;
						break;
					}
				}
			
				// запоминаем бинарную операцию
				for (int j = leftBorder; j <= rightBorder; j++)
				{
					binExpr.push_back(expr[j]);
				}
				cout << binExpr << endl;
				//leftBorder--;
				rightBorder++;
				// удаляем бинарную операцию и скобки если они есть из строки
				

				//cout << leftBorder << ' ' << rightBorder << endl;
				expr.erase(leftBorder, rightBorder - leftBorder);

				cout << expr << endl;

				// вставляем на место бинарной операции ее значение

				expr.insert(leftBorder, binaryCalculation(binExpr));
				cout << expr << " 207" << endl;
				break;
			}


		}
	}


	//// если в строке только один знак сразу возвращаем ответ
	//signCount = 0;
	//for (int i = 0; i < expr.size(); i++){
	//	if (expr[i]<'0' || expr[i]>'9') signCount++;
	//}

	//if (signCount == 1) return stoi(binaryCalculation(expr));
	// рекурсивный выхов функции
	expr = calculate(expr);
	cout << "225" << endl;
	cout << expr << endl;
//	return stoi(expr);

	return 0;
}

int main(){
	

	//cout << calculate("4+4*(5+13)") << endl;

	

	string a = "(35+34)*359";

	cout << findNextSymbol(0, a) << endl;
	findBinaryExpression(a).show();
	


}