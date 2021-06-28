#include <iostream>
using namespace std;
#include "Set.h"

// default constructor creates an empty set
Set::Set(void):size(0),elems(){} //�⺻������

// array copy function, local to this file
static void array_copy(int a[], const int b[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

// copy constructor
Set::Set(const Set& s) //���� ���縦 ���ؼ� const ������ �Ű������� �����;� �Ѵ�.
{
	this->size = s.size; //��������� �޸� ��������� ��� ������� �����;� �Ѵ�. size ���� �����´�.
	array_copy(this->elems, s.elems, size); //elems �迭�� �����´�.

}

// creates a set from an array
Set::Set(int a[], int n)
{	
	size = n; //n�� ũ�⸦ size�� ����
	array_copy(elems, a, n); //elems �迭�� a �迭�� n�� ũ�⸸ŭ �����Ѵ�.
}

// return set size
int Set::getsize()
{
	return size; 
}

// return the element indexed by i; the lowest index is 1
int Set::get(int i)
{
	if (i < 1 || i > size) {
		cerr << "error in Set::get(): index out of bounds" << endl;
		cerr << "returning 0" << endl;
		return 0;
	}
	else
		return elems[i - 1];
}

// set union
Set Set::operator+(Set s)
{
	int i, j, n;
	int a[2 * MAXSIZE];

	n = size;
	array_copy(a, elems, n);
	for (j = 0; j < s.size; j++) {
		for (i = 0; i < n; i++)
			if (a[i] == s.elems[j])
				break;
		if (i == n)
			a[n++] = s.elems[j];
	}

	return Set(a, n);
}

// set difference
Set Set::operator-(Set s)
{
	
	bool check; //������ ���Ұ� �ִ��� Ȯ���ϱ� ���� bool
	int a[MAXSIZE]; //�������� ����� �ޱ� ���� �迭 ����
	int n = 0; //�迭�� size�� ���� int�� ���� n ����
	for(int i=0; i<size;i++){//this�� ��������� �ε����� ����ϴ� int i�� ������Ŵ
		check = true; //�켱�� �⺻������ true ���� �ξ�, ������ ���Ұ� ���� �ÿ��� true���� ��� �̾.
		for (int j = 0; j < s.size; j++) {//Set s�� ��������� �ε����� ����ϴ� int j �� ������Ŵ
			if (s.elems[j] == elems[i]) //���� ������ ���Ұ� �ִٸ� check�� false ���� ��/
				check = false;
		}
		if (check) //���� check�� false�� ���ߴٸ� �������� �����ϴ� a�� �߰����� �ʴ´�.
			a[n++] =elems[i];
	}

	return Set(a, n); //this �� ���ؼ� s�� ��ġ�� �ʴ� ���Ҹ��� �߰��� a�迭�� ���ο� Set�� �ν��Ͻ��� ����� �����Ѵ�.
}

// set assignment; return the assigned set
Set Set::operator=(Set s)//������ �����ε�
{
	size = s.size; //������ ����
	array_copy(elems, s.elems, size); //�迭 ����
	return (*this);//this ��ü�� �������̹Ƿ� Set������ ��ȯ ���� *this ��ȯ
}

// subset relation test
int Set::operator>=(Set s) //�κ������� ���ϴ� ���̱� ������ ���� �ڱ��ڽŰ� ���� �����̾ �ȴ�.
{
	Set a = s - *this; //s���� this�� �������� �Ͽ����� size�� 0�̶�� ���Ұ� ���ٴ� �ǹ̷�, s�� this �� �κ������̶�� �ǹ��̴�.
	if (!a.size) //size�� 0�̸� �κ������̹Ƿ�, !0=1
		return 1;
	else
		return 0; //size�� 0�� �ƴϹǷ� �κ������� �ƴ�.

}

// set equality test
int Set::operator==(Set s)
{
	Set a = s - *this;
	Set b = *this - s; //���ο� ���� �������� �������̶�� ���� �����̴� 
	if (a.size == b.size&&!a.size&&!b.size) //����� ���� ���� 0�̶�� ���� ����
		return 1;
	return 0;

}

// proper subset relation test
int Set::operator>(Set s)
{
	Set a = s - *this; //�ռ� ���ǵ� �κ����� �Ǵ� ����� ������, ���κ������� �ڱ� �ڽŰ� ������ �����ؾ��Ѵ�. ���� ���� ����� ���ٸ�, ���� ���� ����(�� �ڱ��ڽ�)�̹Ƿ� 0�� �����Ѵ�.
	if (s.size != this->size) {
		if (!a.size)
			return 1;
		else
			return 0;
	}
	return 0;
}

// element membership test; return 1 if (*this) contains x
int Set::operator>>(int x) 
{
	for (int i = 0; i < size; i++) //this�� ���Ҹ� Ž���� x�� ���� ���� ���Ұ� �ִٸ� 1�� ��ȯ�Ѵ�.
		if (this->elems[i] == x)
			return 1;
	return 0;
}