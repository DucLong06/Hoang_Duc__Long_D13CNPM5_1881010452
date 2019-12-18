#include<bits/stdc++.h>
 
#define maxSize 1000
 
using namespace std;

struct sach
{
	string masach;
	string tensach;
	string tentacgia;
	int namsx;
	string nhaxb;
	int giathanh;
};
struct List
{
	sach elem[maxSize];
	int size;
};
void initialize(List *L)
{
 	(*L).size = 0;	
}
bool isFull(List L)
{
	return (L.size == maxSize);
}
bool isEmpty(List L)
{
	return (L.size == 0);
}
void remove(List *L, sach x)
{
	
}
sach inputOfData()
{
	sach s;
	cin.ignore();
	cout<<"nhap ma sach : ";
	getline(cin,s.masach);
	cout<<"nhap ten sach : ";
	getline(cin,s.tensach);
	cout<<"nhap ten tac gia :";
	getline(cin,s.tentacgia);
	cout<<"nhap ten nha xuat ban :";
	getline(cin,s.nhaxb);
	cout<<"nhap nam san xuat : ";
	cin>>s.namsx;
	cout<<"nhap gia thanh : ";
	cin>>s.giathanh;
	return s;
}
void ouputOfData(sach s)
{
	cout<<s.masach<<setw(15)<<s.tensach<<setw(15)<<s.tentacgia<<setw(15)<<s.nhaxb<<setw(15)<<s.namsx<<setw(15)<<s.giathanh<<endl;
}
void input(List *L)
{
	cout << "Nhap so phan tu cua danh sach :";
	cin >> (*L).size;
	for (int i = 0 ; i<(*L).size ; i++)
	{
		cout << "nhap phan tu thu "<<i+1<<":"<< endl;
		(*L).elem[i] = inputOfData();
	}
}
void output(List L)
{
	cout << "danh sach :" << endl;
	for (int i = 0 ; i < L.size ; i++)
	{
		ouputOfData(L.elem[i]);
		cout << endl ;
	}
}
int main ()
{
	List L;
    initialize(&L);
    input(&L);
    output(L);
	return 0;
}
