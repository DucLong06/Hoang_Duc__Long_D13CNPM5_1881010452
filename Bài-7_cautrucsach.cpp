#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct sach{
	int masach;
	string tensach;
	string tentacgia;
	int namsx;
	string nhaxb;
	int giathanh;
};

struct node
{
	sach data;
	struct node* pNext;
};
typedef struct node Node;

struct list{
	Node *pHead;
	Node *pTail;
};
typedef struct list List;

int kiemtrarong(List l)
{
	if(l.pHead==NULL)
	{ 
		return 1;
	} return 0;
}

void khoitao(List &l)
{
	l.pHead=l.pTail=NULL;
}

Node *KhoitaoNode(sach s)
{
	Node *p=new Node;
	if(p==NULL)
    {
    	cout<<"\nkhong du bo nho de cap phat";
	}
	p->data=s;
	p->pNext=NULL;
	return p;
}

void Chendau(List &l,Node *p)
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

void xuatsach(sach s)
{
	cout<<setw(5)<<s.masach<<s.tensach<<s.tentacgia<<s.nhaxb<<s.namsx<<s.giathanh<<endl;
}

void duyetlist(List l)
{
	for(Node *k=l.pHead;k!=NULL;k=k->pNext)
	{
		xuatsach(k->data);
	}
}
Node *sapxep(List &l)
{
	for(Node *p=l.pHead;p!=l.pTail;p=p->pNext)
	{
		for(Node *q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->data.namsx>q->data.namsx)
			{
				swap(p->data,q->data);
			}
		}
	}
}
void show(List &l) 
{
    Node *p = l.pHead;
    cout << "Du lieu trong Linked la:" << endl;
    while (p != NULL)
    {
        xuatsach(p->data);
        p = p->pNext;
    }
    cout << endl;
}
int main()
{
	List l;
	sach s;
	khoitao(l);
	int n;
	cout<<"nhap so luong sach :";cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nthong tin cua sach thu \t"<<i+1<<": la \n ";
		cout<<"nhap ma sach ";cin>>s.masach;
		cout<<"nhap ten sach :";fflush(stdin);getline(cin,s.tensach);
		cout<<"nhap ten tac gia :";fflush(stdin);getline(cin,s.tentacgia);
		cout<<"nhap ten nha xuat ban :";fflush(stdin);getline(cin,s.nhaxb);
		cout<<"nhap nam san xuat ";cin>>s.namsx;
		cout<<"nhap gia thanh ";cin>>s.giathanh;
		Node *p=KhoitaoNode(s);
		chencuoi(l,p);
		
	}
	show(l);
	cout<<"\n danh sach da nhap la :\n";
	duyetlist(l);
	sapxep(l);
	cout<<"danh sach sau khi sap xep la \n:";
	duyetlist(l);
	
}
