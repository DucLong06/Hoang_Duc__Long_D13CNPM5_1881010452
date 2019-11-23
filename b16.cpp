#include<bits/stdc++.h>

using namespace std;

struct stackl
{
	int top;
	int nodes[100];
};
void tao(struct stackl *S)
{
	S->top=0;
}
bool ktr(struct stackl S)
{
	return (S.top ==0);
}
bool ktd(struct stackl S)
{
	return (S.top == 99);
}
void push(struct stackl *S,char  x)
{
	if (ktd(*S))
		cout << "\n Ngan xep da day";
	else S->nodes[++S->top]=x;
}
void pop(struct stackl *S, int *x)
{
	if(ktd(*S))
		cout << "\n Ngan xep da day";
	else
	{
		*x = S->nodes[S->top];
		(S->top)--;
	}
}

int main ()
{
	int n,pn,pd;
	cout << "nhap N :";
	cin >> n;
	struct stackl S;
	tao(&S);
	pn=n;
	cout << "So o he 16 la :";
	while (pn != 0)
	{
		pd = pn%16;
		pn = pn/16;
		if (pd==10)
			push(&S,'A');
		else if (pd ==11)
			cout << "B";
		else if (pd ==12)
			cout << "C";
		else if (pd ==13)
			cout << "D";
		else if (pd ==14)
			cout << "E";
		else if (pd ==15)
			cout << "F";
		else
		push(&S,pd);
	}
	while (!ktr(S))
	{
		pop(&S,&pn);
		cout << pn;
	}
	return 0;
}
