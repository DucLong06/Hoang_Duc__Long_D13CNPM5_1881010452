#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct giangvien{
	int magv;
	string tengv;
	int mucluong;
	string hocvi;
};

struct node{
	giangvien data;
	struct node *pNext;
};
typedef struct node Node;

struct list{
	node *pHead;
	node *pTail;
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

Node *khoitaoNode(giangvien gv)
{
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<" khong du bo nho de cap phat :";
	}
	p->data=gv;
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

void XoaDau(List &l)
 {
	if(kiemtrarong(l)==1) 
	{
		return;
	}
	Node * p = l.pHead;
	l.pHead = l.pHead->pNext;   
	delete p;
}

void XoaCuoi(List &l) 
{
	if (kiemtrarong(l)==1) 
	{
		return;
	}
	for (Node *k = l.pHead; k != NULL; k = k->pNext) 
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext =NULL;
			l.pTail = k;
		}
	}
}
void XoaPTBatKy(List &l,int magv1)
{
	if(l.pHead->data.magv==magv1)
	{
		XoaDau(l);
	}
	else if(l.pTail->data.magv==magv1)
	{
		XoaCuoi(l);
	}
	else 
	{
		Node *g=new Node;
		for (Node *k = l.pHead; k != NULL; k = k->pNext) 
		{
			if(k->data.magv==magv1)
			{
				g->pNext=k->pNext;
				delete k;
				return;
			}
			g=k;
		}
	}
}
void xuatGV(giangvien gv)
{
	cout<<setw(5)<<gv.magv<<setw(5)<<gv.tengv<<setw(5)<<gv.mucluong<<setw(5)<<gv.hocvi<<endl;
}
void duyetlist(List l)
{
	for (Node *k = l.pHead; k != NULL; k = k->pNext) 
	{
		xuatGV(k->data);
	}
}
Node *timkiem(List l, int magv1)
{
		for (Node *k = l.pHead; k != NULL; k = k->pNext) 
		{
			if(k->data.magv==magv1)
			{
				return k;
			}
		}
}
int main()
{
	List l;
	giangvien gv;
	khoitaoList(l);
	int n;
	cout <<"Nhap so luong giang vien: ";cin >>n;
	for(int i =0; i<n; i++)
	{
		cout<<"nhap thong tin giang vien thu \t"<< i+1 <<":\n";
		cout <<"Nhap ma gv: "; cin>>gv.magv;
		cout <<"Nhap ten: ";fflush(stdin);	getline(cin,gv.tengv);
		cout <<"Nhap muc luong:"; cin>>gv.mucluong;
		cout <<"Nhap hoc vi: "; fflush(stdin); getline(cin,gv.hocvi);
		Node *p=khoitaoNode(gv);
		chencuoi(l,p);
	}
	cout<<endl<<"\n danh sach giang vien sau khi nhap:\n "<<endl;
	duyetlist(l);
	int magv1;
	cout<<"\nnhap magv can xoa :";
	cin>>magv1;
	Node *kq=timkiem(l,magv1);
	if(kq!=NULL)
	{
		cout<<"\ntim thay sinh vien can xoa !";
		cout<<"\ndanh sach truoc khi xoa la :";
		duyetlist(l);
		XoaPTBatKy(l,magv1);
		cout<<"\ndanh sach sau khi xoa la :";
		duyetlist(l);
	}
	else
	{
		cout<<"\nkhong tim thay sinh vien can xoa !";
	}
}
