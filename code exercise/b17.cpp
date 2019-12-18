#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
} ;
typedef struct node *Node;

void tao(Node &T)
{
	T = NULL;
}
void printNodeInfo(Node pnode)
{
	//cout << " - Data: " << pnode->data << endl;
	cout << pnode->data << " ";
}
int chenDuLieu()
{
	int data;
	cout << "-Data :";
	cin >> data;
	return data;
}
void chenCay(Node &T, int x)
{
    Node q;
    if(T==NULL)
    {
        q = new node;
        q->data=x;
        q->left=NULL;
        q->right=NULL;
        T=q;
    }
    else if (x<T->data)
    {
        chenCay(T->left,x);
    }
    else if(x>T->data)
    {
        chenCay(T->right,x);
    }
}
Node tim(Node T, int x)
{
    Node q;
    q=T;
    if (q!= NULL)
    {
        if (x<q->data)
            tim(q->left,x);
        else if (x>q->data)
            tim(q->right,x);
        else return q;
    }
    else return NULL;
}
void preOrder(Node T)
{
	if(T!=NULL)
	{
		printNodeInfo(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}
int main()
{
	int n;
	cout << "nhap N :";
	cin >> n;
	Node T;
	tao(T);
	for ( int i = 0 ; i < n ; i++)
	{
		cout << "Nhap thong tin du lieu " << i + 1 <<":"<<endl;
		int data = chenDuLieu();
		chenCay(T,data);
	}
	cout << "===> Danh sach du lieu vua nhap (PreOder): " << endl;
	preOrder(T);

	return 0;
}
