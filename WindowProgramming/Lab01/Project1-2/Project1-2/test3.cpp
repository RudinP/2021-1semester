#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

void main() {
	char s[10];
	s[9] = '\0';
	srand((unsigned) time(NULL));
	for (int i = 0; i < 9; i++) {
		s[i] = rand() % 9 + '1';
		for (int j = 0; j < i; j++)
			if (s[i] == s[j])
				i--;
	}
	cout << "s = " << s << endl;
}