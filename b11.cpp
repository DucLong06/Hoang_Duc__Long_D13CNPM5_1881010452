#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
struct mathang{
	string mahang;
	string tenhang;
	string nhomhang;
	int giaban;
};
typedef struct mathang MatHang;

struct node{
	MatHang data;
	struct node *pNext;
	struct node *pRev;
};
typedef struct node Node;

struct list{
	Node *pHead;
	Node *pTail;
};
typedef struct list List;

void khoitao(List &l)
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

Node *khoitaoNode(MatHang mh)
{
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<"\nkhong du bo nho !";
	}
	p->data=mh;
	p->pNext=NULL;
	p->pRev=NULL;
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
		l.pHead->pRev=p;
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void Chencuoi(List &l,Node *p)
{
	if(kiemtrarong(l)==1)
	{
		l.pHead=l.pTail=p;
	}
	else
	{
		l.pTail->pNext=p;
		p->pRev=l.pTail;
		l.pTail=p;
	}
}

void Chensau(List &l,Node *p,Node *q)
{
	if (q ->pNext == NULL)
	{

		q ->pNext = p;
		p ->pRev = q;
		l.pTail = p;
	}
	else
	{
		p ->pNext = q ->pNext;
		q ->pNext ->pRev = p;
		q ->pNext = p;
		p ->pRev =q;
	}
}

void xuat(MatHang mh)
{
		cout<<"\t"<<mh.mahang<<"\t"<<mh.tenhang<<"\t"<<mh.nhomhang<<"\t"<<mh.giaban<<endl;
}
void duyetlist(List &l) 
{

	for(Node *k=l.pHead;k!=NULL;k=k->pNext)
	{
		xuat(k->data);
	}
	
}


void sapxep(List l)
{
	for(Node *p = l.pHead; p!= l.pTail; p = p->pNext)
	{
		for(Node *q = p->pNext; q!= NULL; q = q->pNext)
		{
			if(p->data.mahang>q->data.mahang)
			{
				swap(p->data, q->data);
			}
		}
	}
}

void timkiem(List l,string a,MatHang mh)
{
	int temp = 0;
	for(Node *k=l.pHead;k!=NULL;k=k->pNext)
	{
		if(k->data.mahang.compare(a)==0)
		{
			cout<<"\nthong tin mat hang la :\n";
			cout<<k->data.mahang<<k->data.tenhang<<k->data.nhomhang<<k->data.giaban<<endl;
			temp++;
		}
	}
	if(temp == 0)
	{
		cout <<endl<<"Khong tim thay mat hang !"<<endl;
		cout<<"nhap ma hang :";fflush(stdin);getline(cin,mh.mahang);
		cout<<"nhap vao ten mat hang :";fflush(stdin);getline(cin,mh.tenhang);
		cout<<"nhap vao nhom hang :";fflush(stdin);getline(cin,mh.nhomhang);
		cout<<"nhap gia ban :";cin>>mh.giaban;
		Node *p=khoitaoNode(mh);
		Chencuoi(l,p);
		sapxep(l);
		duyetlist(l);
	}
}

void xoanode(List &l, string a)
{
	int temp = 0;
	for(Node *k = l.pHead; k!= NULL; k = k->pNext)
	{
		if(k->data.tenhang.compare(a) == 0)
		{
			temp++;
			if(k == l.pTail)
			{
				cout <<endl<<"Tim thay mat hang !"<<endl;
				Node *temp1 = new Node;
				temp1 = k->pRev;
				temp1->pNext = NULL;
				l.pTail = temp1;
				delete k;
			}
			else
			{
				cout <<endl<<"Tim thay mat hang !"<<endl;
				Node *temp1 = new Node;
				temp1 = k->pRev;
				temp1->pNext = k->pNext;
				k->pNext->pRev = temp1;
				delete k;
			}
		}
	}
	if(temp == 0)
	{
		cout<<endl<<"Khong tim thay mat hang !";
	}
}


int main()
{
	List l;
	MatHang mh;
	khoitao(l);
	int n;
	cout<<"\nnhap vao so luong mat hang :";cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"nhap thong tin mat hang thu "<<i+1<<":\n";
		cout<<"nhap ma hang :";fflush(stdin);getline(cin,mh.mahang);
		cout<<"nhap vao ten mat hang :";fflush(stdin);getline(cin,mh.tenhang);
		int choose;	
		cout<<"nhap nhom hang:1-hang thoi trang,2-hang tieu dung,3-hang dien may,4-hang gia dung)";
		cin>>choose;
		do
		{
			if(choose==1)
				cin>>mh.nhomhang;
			else if(choose==2)
				cin>>mh.nhomhang;
			else if(choose==3)
				cin>>mh.nhomhang;
			else if(choose==4)
				cin>>mh.nhomhang;	
		}
		while(choose<1 || choose>4);
		cout<<"nhap gia ban :";cin>>mh.giaban;
		Node*p=khoitaoNode(mh);
		Chencuoi(l,p);
	}
	cout<<"\nthong tin mat hang da nhap la :\n";
	duyetlist(l);
	cout<<"\n mat hang sau khi sap xep la :\n";
	sapxep(l);
	duyetlist(l);
	string a;
	cout<<"nhap ma hang can tim :";fflush(stdin);getline(cin,a);
	timkiem(l,a,mh);
	
	
}


















