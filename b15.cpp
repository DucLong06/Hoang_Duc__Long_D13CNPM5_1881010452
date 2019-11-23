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
void push(struct stackl *S,int  x)
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
void tach(struct stackl *S,int n)
{
	int l;
	while ( n!=0)
	{
		l=n%10;
		n=n/10;
		push(S,l);
	}
}
int tinh(struct stackl *S,int n)
{
	int l=S->nodes[S->top],d=0;
	while (!ktr(*S))
	{
		pop(S,&l);
		d+=l;
	}
	return d;
}
int main ()
{
	int n;
	cout << "nhap N :";
	cin >> n;
	struct stackl S;
	tao(&S);
	tach(&S,n);
	cout << "tong cac chu so la : "<<tinh(&S,n);
	return 0;
}
