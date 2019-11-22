#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct khachhang{
	int makh;
	string loaikh;
	string ten;
	string diachi;
	string sdt;
};
typedef struct khachhang Khachhang;

struct node{
	Khachhang data;
	struct node *pNext;
};
typedef struct node Node;

struct list{
	Node *pHead;
	Node *pTail;
};
typedef struct list List;

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

Node *KhoitaoNode(Khachhang kh)
{
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<"\nkhong du bo nho !";
	}
	p->data=kh;
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
		Node*p=l.pHead;
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
	for(Node *k=l.pHead; k!=NULL; k=k->pNext)
	{
		if(k->pNext= l.pTail)
		{
			delete l.pTail;
			k->pNext=NULL;
			l.pTail=k;
			return ;	
		}
	}
}

void XoaPTBatKy(List &l,int makh1)
{
	if(kiemtrarong(l)==1)
	{
		return;
	}
	if(l.pHead->data.makh==makh1)
	{
		xoadau(l);
	}
	else if(l.pTail->data.makh==makh1)
	{
		xoacuoi(l);
	}
	else 
	{
		Node *g=new Node;
		for (Node *k = l.pHead; k != NULL; k = k->pNext) 
		{
			if(k->data.makh==makh1)
			{
				g->pNext=k->pNext;
				delete k;
				return;
			}
			g=k;
		}
	}
}

void xuat(Khachhang kh)
{
	cout<<setw(5)<<kh.makh<<setw(5)<<kh.loaikh<<setw(5)<<kh.ten<<setw(5)<<kh.diachi<<setw(5)<<kh.sdt<<endl;
}

void duyetlist(List l)
{
	for (Node *k = l.pHead; k != NULL; k = k->pNext) 
	{
		xuat(k->data);
	}
}
Node *sapxep(List &l)
{
	for(Node *p=l.pHead;p!=l.pTail;p=p->pNext)
	{
		for(Node *q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->data.ten>q->data.ten)
			{
				swap(p->data,q->data);
			}
		}
	}
}

int main()
{
	List l;
	Khachhang kh;
	khoitaolist(l);
	int n;
	cout<<"\nnhap vao danh sach cac khach hang :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"thong tin cua khach hang thu \t"<<i+1<<"\n";
		cout<<"nhap ma khach hang :";cin>>kh.makh;
		cout<<"nhap vao loai khach hang :"; fflush(stdin);getline(cin,kh.loaikh);
		cout<<"nhap vao ten khach hang :"; fflush(stdin);getline(cin,kh.ten);
		cout<<"nhap vao dia chi cua khach hang :"; fflush(stdin);getline(cin,kh.diachi);
		cout<<"nhap vao so dien thoai khach hang :"; fflush(stdin);getline(cin,kh.sdt);
		Node *p=KhoitaoNode(kh);
		chencuoi(l,p);
	}
	cout<<"\nthong tin nhan vien sau khi nhap la :\n";
	duyetlist(l);
	sapxep(l);
	cout<<"\ndanh sach khach hang sau khi sap xep la :\n";
	duyetlist(l);
}
