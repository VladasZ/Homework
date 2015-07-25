#include <iostream>
#include <string>   
#include "checkHooks.cpp"



using namespace std;

string binaryCalculation(string expr){
	//cout << expr << " = ";
	int res;
	int a, b, signPos; 
	string str_a, str_b, str_res;
	for (int i = 0; i < expr.size(); i++){
		if ((expr[i] < '0' || expr[i] > '9'))// ���� ���� �������� �� �����
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
	// ������������ ������ � int
	a = stoi(str_a);
	b = stoi(str_b);

	// ��������� ���������� � ����������� �� �����

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
	
	// ������������ int ������� � string
	str_res = to_string(res);

	//cout << str_res;
	
	return str_res;
}

int calculate(string expr){
	
	// ��������� ������������ ����������� ������
	Stack a = expr;
	if (!a.checkHooks())
	{
		cout << "Hooks error!" << endl;
		return 0;
	}

	// ���� � ������ ������ ���� ���� ����� ���������� �����
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
				// ���������� ������� �������� ��������
				rightBorder = i - 2;
				for (int j = i - 2; j >= 0; j--)
				{
					if (expr[j] == '(')
					{
						leftBorder = j+1;
						break;
					}
				}
				cout << leftBorder << ' ' << rightBorder << endl;
				// ���������� �������� ��������
				for (int j = leftBorder; j <= rightBorder; j++)
				{
					binExpr.push_back(expr[j]);
				}
				cout << binExpr << endl;
				leftBorder--;
				rightBorder++;
				// ������� �������� �������� � ������ ���� ��� ���� �� ������
				if (expr[leftBorder-1] == '(') leftBorder--;
				if (expr[rightBorder] == ')') {
					rightBorder++; cout << "bla" << endl;
				}
			
				cout << leftBorder << ' ' << rightBorder << endl;
				expr.erase(leftBorder, rightBorder-leftBorder);

				cout << expr << endl;

				// ��������� �� ����� �������� �������� �� ��������

				expr.insert(leftBorder, binaryCalculation(binExpr));
				cout << expr << endl;

			}

			if (expr[i + 1] == '(')
			{
				// ���������� ������� �������� ��������
				leftBorder = i + 2;
				for (int j = i + 2; j <= expr.size(); j++)
				{
					if (expr[j] == ')')
					{
						rightBorder = j - 1;
						break;
					}
				}
				cout << leftBorder << ' ' << rightBorder << endl;
				// ���������� �������� ��������
				for (int j = leftBorder; j <= rightBorder; j++)
				{
					binExpr.push_back(expr[j]);
				}
				cout << binExpr << endl;
				leftBorder--;
				rightBorder++;
				// ������� �������� �������� � ������ ���� ��� ���� �� ������
				if (expr[leftBorder - 1] == '(') leftBorder--;
				if (expr[rightBorder] == ')') {
					rightBorder++; cout << "bla" << endl;
				}

				cout << leftBorder << ' ' << rightBorder << endl;
				expr.erase(leftBorder, rightBorder - leftBorder);

				cout << expr << endl;

				// ��������� �� ����� �������� �������� �� ��������

				expr.insert(leftBorder, binaryCalculation(binExpr));
				cout << expr << endl;
			} 
			
			if (1){
				// ���������� ������� �������� ��������
				
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
				cout << leftBorder << ' ' << rightBorder << endl;
				// ���������� �������� ��������
				for (int j = leftBorder; j <= rightBorder; j++)
				{
					binExpr.push_back(expr[j]);
				}
				cout << binExpr << endl;
				//leftBorder--;
				rightBorder++;
				// ������� �������� �������� � ������ ���� ��� ���� �� ������
				

				//cout << leftBorder << ' ' << rightBorder << endl;
				expr.erase(leftBorder, rightBorder - leftBorder);

				cout << expr << endl;

				// ��������� �� ����� �������� �������� �� ��������

				expr.insert(leftBorder, binaryCalculation(binExpr));
				cout << expr << endl;
				//i = 0;
			}


		}
	}

	//binaryCalculation(expr);

	return 0;
}

int main(){
	

	cout << calculate("(4*4)") << endl;

	


}