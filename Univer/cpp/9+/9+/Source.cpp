#include <iostream>

using namespace std;

int recursiveDigitCount(int number)
{
	if (number > 0)
	{
		return recursiveDigitCount(number / 10) + 1;
	}

	return 0;
}

int digitCount(int number)
{
	int result = 0;

	while (number > 0)
	{
		number /= 10;
		result++;
	};

	return result;
}


int main()
{
	cout << digitCount(42732) << endl;
	cout << recursiveDigitCount(4739426) << endl;
}

int return2007()
{
	return 2007;
}