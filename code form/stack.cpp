//#include "pch.h"

#include <iostream>
#include<string>

#define MAX_SIZE 100

using namespace std;

typedef char TypeOfItem;

struct Stack
{
	int top;
	TypeOfItem nodes[MAX_SIZE];
};

void initialize(Stack *s)
{
	s->top = -1;
}

bool isEmpty(Stack s)
{
	return s.top == -1;
}

bool isFull(Stack s)
{
	return s.top == MAX_SIZE - 1;
}

int sizeOfStack(Stack s)
{
	return s.top + 1;
}

void push(TypeOfItem x, Stack *s)
{
	if (isFull(*s))
		cout << "Ngan xep da day" << endl;
	else s->nodes[++(s->top)] = x;
}

void pop(Stack *s, TypeOfItem *x)
{
	if (isEmpty(*s))
		cout << "Ngan xep rong" << endl;
	else
	{
		*x = s->nodes[s->top];
		s->top--;
	}
}

void bai_toan_doi_co_so()
{
	int pd, pn, a;
	char x;
	int coso;
	Stack s;

	initialize(&s);
	cout << "Nhap so o he co so 10 la: ";
	cin >> a;
	cout << "Nhap co so can chuyen: ";
	cin >> coso;

	pn = a;
	while (pn != 0)
	{
		pd = pn % coso;
		if (pd >= 10) x = 'A' + pd % 10;
		else x = '0' + pd;
		push(x, &s);
		pn = pn / coso;
	}

	cout << "So o he co so 10 la: " << a << endl;
	cout << "So o he co so " << coso << " la: ";

	while (!isEmpty(s))
	{
		pop(&s, &x);
		cout << x;
	}

	cout << endl;
}

void bai_toan_chuoi_ngoac_don_hop_le()
{
	char str[] = "(())()";
	char x;
	Stack s;

	initialize(&s);
	
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(') push('(', &s);
		else if (str[i] == ')') pop(&s, &x);
	}
	
	if (isEmpty(s))
		cout << "Bieu thuc " << str << " DUNG" << endl;
	else cout << "Bieu thuc " << str << " SAI" << endl;
}

int main()
{
	//bai_toan_doi_co_so();
	bai_toan_chuoi_ngoac_don_hop_le();
}