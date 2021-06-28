#include "Stack.h"
#include <iostream>

CStack::CStack() {
	store = new double[100];
	capacity = 100;
	top = 0;
}
CStack::CStack(int size) {
	store = new double[size];
	capacity = size;
	top = 0;
}
CStack::~CStack() {
	if (store != NULL)
		delete(store);
}
double CStack::pop(CStack& s) {
	if (s.top > 0)
		return s.store[--s.top];
	else {
		cerr << "Error: pop from an empty stack" << endl;
		return 0;
	}
}
void CStack::push(CStack& s, double val) {
	if (s.top < s.capacity) {
		cout << "push " << val << endl;
		s.store[s.top++] = val;
	}
	else
		cerr << "Error: stack full, can't push" << endl;
}

