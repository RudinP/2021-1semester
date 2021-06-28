#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

int GetRandom() {
	srand((unsigned)time(NULL));
	return rand() % 100;
}

void AddQuiz(int a, int b) {
	int answer;

	cout << a << "+" << b << "=";
	cin >> answer;

	if (answer == a + b)
		cout << "Correct!";
	else
		cout << "Wrong answer!";
}
void main() {
	AddQuiz(GetRandom(), GetRandom());
}
