#include<bits/stdc++.h>

using namespace std;

struct GiangVien
{
    string mgv;
    string ten;
    string hocvi;
    int mlg;
};
typedef GiangVien gv;
struct NODE
{
    gv data;
    NODE *next;
};
typedef NODE *node;
void tao(node *L)
{
    *L=NULL;
}
bool isEmpty(node L)
{
    return((L==NULL) ? true : false);
}
node createNode(gv data)
{
    node newnode = new NODE;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void printNodeInfo(node L)
{
    cout << "Ho ten giang vien :" << L->data.ten << endl;
    cout << "Ma giang vien :" << L->data.mgv << endl;
    cout << "hoc vi :" << L->data.hocvi << endl;
    cout << "Muc luong :" << L->data.mlg << endl;
}
void insertHead(node *L, gv data)
{
    node newnode = createNode(data);
    if (*L==NULL)
        *L=newnode;
    else
    {
        newnode->next=*L;
        *L=newnode;
    }
}
void insertTail(node *L, gv data)
{
    node newnode = createNode(data);
    if (*L==NULL)
        *L=newnode;
    else
    {
        node p = *L;
        while (p!= NULL)
            p=p->next;
        p->next=newnode;
    }
}
void insertAfter(node q,node *L, gv data)
{
    if (q==NULL)
        cout << "khong them duoc !!!";
    else
    {
        node p= createNode(data);
        q->next=p->next;
        q->next=p;
    }
}

int main()
{
    return 0;
}
