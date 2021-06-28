#include <iostream>
using namespace std;
class CStack
{
	double* store;
	int capacity;
	int top;

public:
	CStack();
	CStack(int);
	double pop(CStack & s);
	~CStack();
	void push(CStack &s, double val);
};
