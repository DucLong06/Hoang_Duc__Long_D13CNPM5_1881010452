#include<bits/stdc++.h>

#define maxSize 1000

using namespace std;

struct Queue
{
	int first,last;
	int Node[maxSize];
};
struct Queue Q;
void initialize(struct Queue *Q)
{
	Q->first=-1;
	Q->last=-1;
}
bool isEmpty(struct Queue Q)
{
	return ((Q.last+1)%maxSize==Q.first);
}
bool isFull(struct Queue Q)
{
	return ((Q.last+2)%maxSize ==Q.first);
}
int sizeQueue(struct Queue Q)
{
	if(isEmpty(Q))
		return 0;
	else if (Q.first<Q.last)
		return (Q.last-Q.first+1);
	else 
		return (Q.last-Q.first+maxSize+1);
}
void addQueue(int x, struct Queue *Q)
{
	if (!isFull(*Q))
	{
		if (isEmpty(*Q))
			Q->first=0;
		Q->last=(Q->last + 1) % maxSize;
		Q->Node[Q->last]=x;
	}
	else 
		cout << "hang doi day";
}
void delQueue(struct Queue *Q,int *x)
{
	if(!isEmpty(*Q))
	{
		*x = Q->Node[Q->first];
		Q->first=(Q->first+1)%maxSize;
	}
	else 
		cout << "hang doi rong";
}
void solve(struct Queue Q)
{
	int x,d=0;
	while (!isEmpty(Q))
	{
		delQueue(&Q,&x);
		cout << x << endl;
	}
	cout << "tong cac chu so la : " << d ;
}
int main()
{
	Queue Q;
	initialize(&Q);
	int n,a;
	cout << "Nhap N:";
	cin >> n;
	for(;n!=0;)
	{
        a = n % 10;
        addQueue(a,&Q);
        n /= 10;
    } 
  	solve(Q);
	return 0;
}
