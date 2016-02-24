#include <iostream>

class Strategy
{
public:
	virtual ~Strategy() {}
	virtual void use(void) = 0;
};

class Strategy_1 : public Strategy
{
public:
	void use(void) { std::cout << "Strategy_1" << std::endl; };
};

class Strategy_2 : public Strategy
{
public:
	void use(void) { std::cout << "Strategy_2" << std::endl; };
};

class Strategy_3 : public Strategy
{
public:
	void use(void) { std::cout << "Strategy_3" << std::endl; };
};

class Context
{
protected:
	Strategy* operation;

public:
	virtual ~Context() {}
	virtual void useStrategy(void) = 0;
	virtual void setStrategy(Strategy* v) = 0;
};

class Client : public Context
{
public:
	void useStrategy(void)
	{
		operation->use();
	}

	void setStrategy(Strategy* o)
	{
		operation = o;
	}
};

int main(int /*argc*/, char* /*argv*/[])
{
	Client customClient;
	Strategy_1 str1;
	Strategy_2 str2;
	Strategy_3 str3;

	customClient.setStrategy(&str1);
	customClient.useStrategy();
	customClient.setStrategy(&str2);
	customClient.useStrategy();
	customClient.setStrategy(&str3);
	customClient.useStrategy();

	return 0;
}