#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
// 배열 s[]에 1에서 9까지의 숫자를 랜덤하게 배열한 문자열을 넣기 위해 s[i]에 랜덤한
// 숫자를 넣은 후, s[] 상의 다른 칸에 있는 숫자와 겹칠 경우, i 값을 후퇴시킨 다음
// 새로 s[i]를 정하는 방법을 사용한다.
void main() {
	char s[10];
	s[9] = '\0';
	srand((unsigned)time(NULL));
	for (int i = 0; i < 9; i++) {
		s[i] = rand() % 9 + '1';
		for (int j = 0; j < 9; j++)
			if (s[i] == s[j])
				i--;
	}
	cout << "s = " << s << endl;
}