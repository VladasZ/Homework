#include <iostream>
#include <string>   
#include "checkHooks.cpp"



using namespace std;

string binaryCalculation(string expr){
	cout << expr << " = ";
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

	cout << str_res;
	
	return str_res;
}

int calculate(string expr){
	Stack a = expr;
	if (!a.checkHooks())
	{
		cout << "Hooks error!" << endl;
		return 0;
	}


	/*for (int i = 0; i < strlen(expr); i++){
		if (expr[i] == '*')
		{
			if (expr[i-1] == ')')
		}*/
	//}
	return 0;
}

int main(){
	

	calculate("6565(454()(54))54(54)");

	





}