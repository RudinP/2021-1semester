#include <iostream>
using namespace std;
#include "Set.h"

void setprint(Set s)
{
	cout << "{";
	for (int i = 1; i <= s.getsize(); i++)
		cout << s.get(i) << ((i < s.getsize()) ? ", " : "");
	cout << "}";
}

void main()
{
	int a[] = { 3, 9, 5 };
	int b[] = { 2, 4, 5, 8, 10 };
	Set s1;
	Set s2(a, 3);
	Set s3 = s2;  // copy constructor is used here
	Set s4(b, 5);


	cout << "SET UNION TEST" << endl;
	s1=s3 + s4;
	cout << "s3 = "; setprint(s3); cout << endl;
	cout << "s4 = "; setprint(s4); cout << endl;
	cout << "s3 + s4 = "; setprint(s1); cout << endl << endl;

	// s1 = s4 - s3

	cout << "SET DIFFERNCE TEST" << endl;
	s1=s4 - s3;
	cout << "s4 = "; setprint(s4); cout << endl;
	cout << "s3 = "; setprint(s3); cout << endl;
	cout << "s4 - s3= "; setprint(s1); cout << endl << endl;

	// test for i = 1, 2, ..., 10 if i is in s4
	cout << "SET MEMBERSHIP TEST" << endl;
	cout << "s4 = "; setprint(s4); cout << endl;
	for (int i = 1; i < 11; i++) { //1~10까지 >>연산자가 1값을반환하면 참으로, is in s4를 출력하고 0을 반환하면 거짓으로 is NOT in s4를 출력한다.
		if (s4 >> i)
			cout << i << " is in s4" << endl<<endl;
		else
			cout << i << " is  NOT in s4" << endl << endl;
	}
	// test if s4 > s1
	// if not print < s1 is NOT a proper subset of s4 >
	cout << "PROPER SUBSET RELATION TEST" << endl;
	cout << "s1 = "; setprint(s1); cout << endl;
	cout << "s4 = "; setprint(s4); cout << endl;
	if (s4 > s1)
		cout << "s1 is a proper subset of s4" << endl << endl;
	else
		cout << " s1 is NOT a proper subset of s4" << endl << endl;

	// test if s2 == s3
	// if not print < s2 is NOT equal to s3 >
	cout << "SET EQUALITY TEST" << endl;
	cout << "s2 = "; setprint(s2); cout << endl;
	cout << "s3 = "; setprint(s3); cout << endl;
	if (s2 == s3)
		cout << "s2 is equal to s3" << endl << endl;
	else
		cout << "s2 is NOT equal to s3" << endl << endl;


}