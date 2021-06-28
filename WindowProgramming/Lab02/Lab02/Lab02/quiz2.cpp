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
	bool checker = true;

	while (checker) {
		cout << a << "+" << b << "=";
		cin >> answer;
		if (answer == a + b) {
			cout << "Correct!";
			checker = false;
		}
		else
			cout << "Wrong answer! Try again" << endl;
	}
}
void main() {
	AddQuiz(GetRandom(), GetRandom());
}
