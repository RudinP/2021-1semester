#include <iostream>
using namespace std;
struct BigInt {
	int digits[100];
	int ndigits;
};

void convert(BigInt* p, const char* s) { 
	int n = 0;
	while (*s != '\0') {
		n++;
		*s++;
	}
	p->ndigits = n;
	while (n >=0)
		p->digits[n--] = *s--;
}


void print(BigInt x) {
	int n = x.ndigits;
	for(int i=0;i<n;i++)
		cout << x.digits[i]-'0';
}

void main() {
	BigInt a;
	convert(&a, "123456789123456789");
	cout << "a = ";
	print(a);
	cout << endl;
}