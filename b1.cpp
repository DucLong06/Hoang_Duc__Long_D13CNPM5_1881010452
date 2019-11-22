#include <bits/stdc++.h>

using namespace std;

struct sv
{
    string malop;
    string msv;
    string ten;
    int ns;
    string qq;
};
struct NODE
{
    sv data;
    NODE *next;
};
typedef struct NODE *node;
sv nhap()
{
    sv sinhvien;

    cin.ignore();
    cout << "nhap ho ten sinh vien :";
    getline(cin, sinhvien.ten);

    cout << "nhap ma lop :";
    getline(cin, sinhvien.malop);

    cout << "nhap ma sinh vien :";
    getline(cin, sinhvien.msv);

    cout << "nhap que quan :";
    getline(cin, sinhvien.qq);

    cout << "nhap nam sinh :";
    cin >> sinhvien.ns;

    return sinhvien;
}
void tao(node *L)
{
    *L = NULL;
}
bool ktrarong(node l)
{
    return ((l == NULL) ? true : false);
}
node taonode(sv data)
{
    node newnode = new NODE;
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}
void innode(node l)
{
    cout << "Ho va ten : " << l->data.ten << endl;
    cout << "ma sinh vien : " << l->data.msv << endl;
    cout << "ma lop : " << l->data.malop << endl;
    cout << "nam sinh : " << l->data.ns << endl;
    cout << "que quan  : " << l->data.qq << endl;
}
void themdau(node *L, sv data)
{
    node newnode = taonode(data);
    if (*L == NULL)
        *L = newnode;
    else
    {
        newnode->next = *L;
        *L = newnode;
    }
}
void themcuoi(node *L, sv data)
{
    node newnode, p;
    newnode = taonode(data);
    if (*L == NULL)
        *L = newnode;
    else
    {
        p = *L;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
    }
}
void duyet(node L)
{
    if (L == NULL)
        cout << "Danh sach rong !!" << endl;
    else
    {
        node q = L;
        int i = 0;
        while (q != NULL)
        {
            cout << "Thong tin sinh vien " << ++i << ":" << endl;
            innode(q);
            q = q->next;
        }
    }
}
void themsau(sv data, node p, node *L)
{
    if (p == NULL)
        cout << "khong them duoc !!!";
    else
    {
        node q = taonode(data);
        q->next = p->next;
        p->next = q;
    }
}
void xoa(node p, node *L)
{
    if (p == NULL)
        cout << "node khong ton tai !!!";
    else
    {
        if (ktrarong(*L))
            cout << "Danh sach rong !!!" << endl;
        else
        {
            if (p == *L)
            {
                *L = (*L)->next;
            }
            node q;
            q = *L;
            while (q != NULL && q->next != p)
            {
                q = q->next;
            }
            q->next = p->next;
        }
        p->next = NULL;
        delete p;
    }
}
void sapxep(node *L)
{
    if (ktrarong(*L))
        cout << "Danh sach rong !!!" << endl;
    else
    {
        for (node i = *L; i->next != NULL; i = i->next)
            for (node j = i->next; j != NULL; j = j->next)
            {
                if (i->data.ten.compare(j->data.ten) > 0)
                {
                    sv data = i->data;
                    i->data = j->data;
                    j->data = data;
                }
            }
    }
}
node tim(string msv, node L)
{
    if (L == NULL)
        return NULL;
    else
    {
        node q;
        q = L;
        while (q != NULL && q->data.msv.compare(msv) != 0)
            q = q->next;
        return q;
    }
}
int main()
{
    int n;
    cout << "nhap so luong sinh vien :";
    cin >> n;

    node L;
    tao(&L);

    for (int i = 0; i < n; i++)
    {
        cout << "NHAP THONG TIN SINH VIEN " << i + 1 << ":" << endl;
        sv sinhvien = nhap();
        themcuoi(&L, sinhvien);
    }

    cout << "////////////////THONG TIN CUA SINH VIEN\\\\\\\\\\\\\\\\ " << endl;
    duyet(L);
    cout << "//////////////TIM KIEM\\\\\\\\\\\\\\" << endl;
    string msv;
    cout << "Nhap ma sinh vien de tim kiem: ";
    cin >> msv;
    node found = tim(msv, L);
    if (found == NULL)
        cout << "Khong tim thay sinh vien voi ma " << msv;
    else
    {
        cout << "Tim thay sinh vien voi ma " << msv << ":" << endl;
        innode(found);

        cout << "///////////Xoa sinh vien khoi danh sach\\\\\\\\\\ " << endl;
        xoa(found, &L);

        cout << "===> Danh sach sinh vien sau khi xoa: " << endl;
        duyet(L);
    }
}

/*******************\
 *  Hoang Duc Long *
 *  D13CNPM5       *
\*******************/
