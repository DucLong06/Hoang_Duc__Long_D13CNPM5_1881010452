#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Nhanvien{
	int manv;
	string tennv;
	int namsinh;
	int hsl;
};

struct node{
	Nhanvien data;
	struct node *pNext;
};
typedef struct node Node;

struct list{
	Node *pHead;
	Node *pTail;
};
typedef struct list List;

void khoitaoList(List &l)
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

Node *khoitaoNode(Nhanvien nv)
{
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<" khong du bo nho de cap phat :";
	}
	p->data=nv;
	p->pNext=NULL;
	return p;
}

void chendau(List &l, Node *p)
{
	if (kiemtrarong(l)==1) 
	{
		l.pHead = l.pTail = p;
	}
	else 
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void chencuoi(List &l, Node *p)
{
	if (kiemtrarong(l)==1) 
	 {
		l.pHead = l.pTail = p;
	}
	else 
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void xuatNV(Nhanvien nv)
{
	cout<<setw(5)<<nv.manv<<setw(5)<<nv.tennv<<setw(5)<<nv.namsinh<<setw(5)<<nv.hsl<<endl;
}
void duyetlist(List l)
{
	for (Node *k = l.pHead; k != NULL; k = k->pNext) 
	{
		xuatNV(k->data);
	}
}
Node *timkiem(List l, int manv1)
{
		for (Node *k = l.pHead; k != NULL; k = k->pNext) 
		{
			if(k->data.manv==manv1)
			{
				return k;
			}
		}
}
int main()
{
	List l;
	Nhanvien nv;
	khoitaoList(l);
	int n;
	cout <<"Nhap so luong nhan vien: ";cin >>n;
	for(int i =0; i<n; i++)
	{
		cout<<"nhap thong tin nhan vien thu \t"<< i+1 <<":\n";
		cout <<"Nhap ma nhan vien: "; cin>>nv.manv;
		cout <<"Nhap ten: ";fflush(stdin);	getline(cin,nv.tennv);
		cout <<"Nhap nam sinh:"; cin>>nv.namsinh;
		cout <<"Nhap hsl:"; cin>>nv.hsl;
		Node *p=khoitaoNode(nv);
		chencuoi(l,p);
	}
	cout<<endl<<"\n danh sach nhan vien sau khi nhap:\n "<<endl;
	duyetlist(l);
	int manv1;
	cout<<"\nnhap ma nhan vien can tim kiem :";
	cin>>manv1;
	Node *kq=timkiem(l,manv1);
	if(kq!=NULL)
	{
		cout<<"\nthong tin nhan vien duoc tim thay la:";
		xuatNV(kq->data);
	}
	else
	{
		cout<<"\nkhong tim thay nhan vien can xoa !";
	}
}

