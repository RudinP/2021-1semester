#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

int GetRandom() {
	srand((unsigned)time(NULL));
	return rand() % 100;
}

int AddQuiz(int a, int b) {
	int answer;

	cout << a << "+" << b << "=";
	cin >> answer;

	if (answer == a + b) {
		cout << "Correct" << endl;
		return 1;
	}
	else {
		cout << "Wrong" << endl;
		return 0;
	}
}

void main() {
	char retry = 'Y';
	int answer = 0;
	int question = 0;
	while (retry == 'Y') {
		question++;
		answer += AddQuiz(GetRandom(), GetRandom());
		cout << "����Ϸ���Y, �ƴϸ� �ƹ� Ű��:";
		cin >> retry;
	}
	cout << answer << " correct answers out of " << question << " problems";
}
