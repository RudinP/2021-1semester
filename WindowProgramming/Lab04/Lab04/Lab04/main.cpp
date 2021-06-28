#include "Stack.h"
#include <iostream>
int main() {
	CStack s;
	CStack s2(3);
	s.push(s, 2.0); s.push(s, 11.0);
	cout << "popped value = " << s.pop(s) << endl;
	cout << "popped value = " << s.pop(s) << endl;

	s2.push(s2, 3.0); s2.push(s2, 12.0); s2.push(s2, 13.0); s2.push(s2, 14.0);
	cout << "popped value = " << s.pop(s2) << endl;
	cout << "popped value = " << s.pop(s2) << endl;

}