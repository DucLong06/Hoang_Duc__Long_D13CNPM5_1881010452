#include<iostream>
#include<iomanip>
#include<string>
#define N 100
using namespace std;

 struct stack
 {
	int top;
	int nodes[N];
};


void khoitaostack(struct stack *s)
{
	s->top=0;
}

int kiemtrarong(struct stack s)
{
	return (s.top==0);
}

int kiemtraday(struct stack s)
{
	return (s.top==N-1);
}

void push(int x,struct stack *s)
{
	if(kiemtraday(*s))
	{
		cout<<"\nngan xep da day :";
	}
	else
	{
		s->top++;
		s->nodes[s->top]=x;
	}
}

void pop(struct stack *s,int *x)
{
	if(kiemtrarong(*s))
	{
		cout<<"\nngan xep rong \n";
	}
	else
	{
		*x=s->nodes[s->top];
		s->top--;
	}
}

int main()
{
	int pn,pd,a,x;
    struct stack s;
	khoitaostack(&s);
	cout<<"\nnhap so he 10 la:";cin>>a;
	pn=a;
	while(pn!=0)
	{
		pd=pn%8;
		push(pd,&s);
		pn=pn/8;
	}
	cout<<"\n so he 10 la :"<<a;
	cout<<"\n so he 8 la :";
	while(!kiemtrarong(s))
	{
		pop(&s,&pn);
		cout<<"\t"<<pn;
	}
}
