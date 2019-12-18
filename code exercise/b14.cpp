#include<bits/stdc++.h>

using namespace std;

struct stackl
{
	int top;
	char nodes[100];
};
void tao(struct stackl *S)
{
	S->top=0;
}
void check(char str[],int n , struct stackl *S)
{
	for (int i=0;i<n;i++)
	{
		if (str[i]=='(')
		{
			(S->top)++;
			S->nodes[S->top]='(';
		}
		else if (str[i]==')')
		{
			if (S->top== 0)
			{
				(S->top)--;
				break;
			}
			else
				(S->top)--;
		}
	}
	if (S->top==0)
		cout << "HOP LE ";
	else
		cout << "KHONG HOP LE ";
}

int main ()
{
	int n ;
	cout << "nhap n :";
	cin >> n;
	char a[n];
	cout << "nhap chuoi dau :";
	for (int i=0;i<n;i++)
		cin >>a[i];
	struct stackl *S;
	tao(S);
	check (a, n, S);
	return 0;
}
