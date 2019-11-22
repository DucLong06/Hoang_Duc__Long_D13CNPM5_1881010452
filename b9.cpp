#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

struct date
{
	int day, month, year;
};
typedef struct date DATE;

struct diem
{
	int point1,point2,point3;
};
typedef struct diem DIEM;

struct SinhVien
{
	string malop;
	string masv;
	string name;
	DATE ngaysinh;
	DIEM point;	
};
typedef struct SinhVien sv;

struct node
{
	sv data;
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;

NODE *newnode(sv x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		cout <<"Khong du bo nho !";
		exit(0);
	}
	p->data = x;
	p->next = NULL;
	p->prev =NULL;
	return p;
}

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

void newlist(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void addtail(LIST &l, NODE *p)
{
	if(l.pHead == NULL && l.pTail == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->next = p;
		p->prev = l.pTail;
		p->next=NULL;
		l.pTail = p;
	}
}

void readlist(LIST l)
{
	int i = 1;
	for(NODE *k = l.pHead; k != NULL; k = k->next)
	{
		cout<<endl<<"+Thong tin sinh vien "<<i<<endl<<endl;
		i++;
		cout <<"Ma lop: "<<k->data.malop<<endl;
		cout <<"Ma sv: "<<k->data.masv<<endl;
		cout <<"Ho ten: "<<k->data.name<<endl;
		cout <<"Ngay sinh: "<<k->data.ngaysinh.day<<"/"<<k->data.ngaysinh.month<<"/"<<k->data.ngaysinh.year<<endl;
		cout <<"Diem 1: "<<k->data.point.point1<<endl;
		cout <<"Diem 2: "<<k->data.point.point2<<endl;
		cout <<"Diem 3: "<<k->data.point.point3<<endl;
		cout <<endl;
	}
}

void sortlist(LIST &l)
{
	for(NODE *p = l.pHead; p!= l.pTail; p = p->next)
	{
		for(NODE *q = p->next; q!= NULL; q = q->next)
		{
			if((p->data.point.point1 + p->data.point.point2 + p->data.point.point3) > (q->data.point.point1 + q->data.point.point2 + q->data.point.point3))
			{
				swap(p->data, q->data);
			}
		}
	}
}

void search(LIST l, string a)
{
	int temp = 0;
	for(NODE *k = l.pHead; k!= NULL; k = k->next)
	{
		if(k->data.name.compare(a) == 0)
		{
			cout <<endl<<"----THONG TIN SINH VIEN TIM KIEM---- "<<endl;
			cout <<"Ma lop: "<<k->data.malop<<endl;
			cout <<"Ma sv: "<<k->data.masv<<endl;
			cout <<"Ho ten: "<<k->data.name<<endl;
			cout <<"Ngay sinh: "<<k->data.ngaysinh.day<<"-"<<k->data.ngaysinh.month<<"-"<<k->data.ngaysinh.year<<endl;
			cout <<"Diem 1: "<<k->data.point.point1<<endl;
			cout <<"Diem 2: "<<k->data.point.point2<<endl;
			cout <<"Diem 3: "<<k->data.point.point3<<endl;
			temp++;
		}
	}
	if(temp == 0)
	{
		cout <<endl<<"Khong tim thay sinh vien !"<<endl;
	}
}

void deletenode(LIST &l, string a)
{
	int temp = 0;
	for(NODE *k = l.pHead; k!= NULL; k = k->next)
	{
		if(k->data.masv.compare(a) == 0)
		{
			temp++;
			if(k == l.pTail)
			{
				cout <<endl<<"Tim thay sinh vien !"<<endl;
				NODE *temp1 = new NODE;
				temp1 = k->prev;
				temp1->next = NULL;
				l.pTail = temp1;
				delete k;
			}
			else
			{
				cout <<endl<<"Tim thay sinh vien !"<<endl;
				NODE *temp1 = new NODE;
				temp1 = k->prev;
				temp1->next = k->next;
				k->next->prev = temp1;
				delete k;
			}
		}
	}
	if(temp == 0)
	{
		cout<<endl<<"Khong tim thay sinh vien !";
	}
}

void addmid(LIST &l, NODE *q, NODE *p)
{
	if(q == NULL)
	{
		p->next = l.pHead;
		l.pHead->prev = p;
		l.pHead = p;
	}
	else if(q == l.pTail)
	{
		
		l.pTail->next = p;
		p->prev = l.pTail;
		l.pTail = p;
	}
	else
	{
		p->next = q->next;
		q->next->prev = p;
		q->next = p;
		p->prev = q;
	}
}

main()
{
	LIST l;
	newlist(l);
	sv x;
	int n;
	cout <<"Nhap so luong sinh vien: ";
	cin >>n;
	cout<<endl<<"---NHAP THONG TIN SINH VIEN----"<<endl<<endl;
	for(int i =0; i<n; i++)
	{
		cout<<"+Nhap thong tin sinh vien "<<i+1<<":"<<endl;
		cout <<"Nhap ma lop: ";fflush(stdin);getline(cin,x.malop);
		cout <<"Nhap ma sv: ";fflush(stdin);getline(cin,x.masv);
		cout <<"Nhap ten: ";fflush(stdin);getline(cin,x.name);
		cout <<"Nhap ngay-thang-nam sinh: ";
		cin >>x.ngaysinh.day>>x.ngaysinh.month>>x.ngaysinh.year;
		cout <<"Nhap diem 1: ";cin >>x.point.point1;
		cout <<"Nhap diem 2: ";cin >>x.point.point2;
		cout <<"Nhap diem 3: ";cin >>x.point.point3;
		NODE *p = newnode(x);
		addtail(l,p);
		cout<<endl;
	}
	cout<<endl<<"----DANH SACH SINH VIEN----"<<endl<<endl;
	readlist(l);
    sortlist(l);
    cout<<"\n danh sach sau khi sap xep la :";
    readlist(l);
    string a;
    cout<<"\nnhap TEN sinh vien can tim :";fflush(stdin);getline(cin,a);
    search(l,a);
    cout<<"\nnhap MA sinh vien can xoa :";fflush(stdin);getline(cin,a);
    deletenode(l,a);
    cout<<"\n danh sach sau khi xoa la :";
    readlist(l);
   }
