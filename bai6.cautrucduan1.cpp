#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct duan{
	int maduan;
	string tenduan;
	string kieuduan;
	float kinhphi;	
};

struct node{
	duan data;
	struct node *pNext;
};
typedef struct node Node;

struct List{
	Node *pHead;
	Node *pTail;
};

void khoitaolist(List &l)
{
	l.pHead=l.pTail=NULL;
}

int kiemtrarong(List l)
{
	if(l.pHead==NULL)
	{
		return 1;
	}return 0;
}

Node *KhoiTaoNode(duan x)
{
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<"\nkhong du bo nho ";
	}
	p->data=x;
	p->pNext=NULL;
	return p;
}

void chendau(List &l,Node *p)
{
	if(kiemtrarong(l)==1)
	{
		l.pHead=l.pTail=p;
	}
	else
	{
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void chencuoi(List &l,Node *p)
{
	if(kiemtrarong(l)==1)
	{
		l.pHead=l.pTail=p;
	}
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void xoadau(List &l)
{
	if(kiemtrarong(l)==1)
	{
		return;
	}
	else
	{
		Node *p=l.pHead;
		l.pHead->pNext=l.pHead;
		delete p;
	}
}

void xoacuoi(List &l)
{
	if(kiemtrarong(l)==1)
	{
		return;
	}
	if(l.pHead->pNext=NULL)
	{
		xoadau(l);
	}
	for(Node *k=l.pHead;k!=NULL;k=k->pNext)
	{
		if(k->pNext==l.pTail)
		{
			delete l.pTail;
			k->pNext=NULL;
			l.pTail=k;
			return;
		}
	}
}

void xuat(duan x)
{
	cout<<setw(5)<<x.maduan<<setw(5)<<x.tenduan<<"\t"<<x.kieuduan<<setw(10)<<x.kinhphi<<endl;
}

void duyetlist(List l)
{
	for(Node *k=l.pHead;k!=NULL;k=k->pNext)
	{
		xuat(k->data);
	}
}

Node *sapxep(List l)
{
	Node *t,*t1;
	t=l.pTail;
	for(Node *p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(Node *q=l.pHead;q!=l.pTail;q=q->pNext)
		{
			if(q->data.kinhphi>q->pNext->data.kinhphi)
			{
				swap(q->data,q->pNext->data);
				t1=q;
			}
		}
		t=t1;
	}
}
int main()
{
	List l;
	duan x;
	khoitaolist(l);
	int n;
	cout<<"\nnhap so luong du an :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n thong tin cua du an thu :"<<i+1<<"\n";
		cout<<"nhap ma du an :";cin>>x.maduan;
		cout<<"nhap ten du an :";fflush(stdin);getline(cin,x.tenduan);
		int choose;	cout<<"nhap kieu du an :";cin>>choose;
		do
		{
			if(choose==1)
				cin>>x.kieuduan;
			else if(choose==2)
				cin>>x.kieuduan;
			else if(choose==3)
				cin>>x.kieuduan;
		}
		while(choose<1 || choose>3);
		cout<<"nhap kinh phi:";cin>>x.kinhphi;
		Node *p=KhoiTaoNode(x);
		chencuoi(l,p);
	}
	cout<<"\n thong tin cua du an sau khi nhap la :\n";
	duyetlist(l);
	sapxep(l);
	cout<<"\n du an sau khi sap xep la :\n";
	duyetlist(l);
}



































