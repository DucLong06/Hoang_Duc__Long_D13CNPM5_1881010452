#include <iostream>
using namespace std;

struct phanso {
	int ts;
	int ms;
	void nhap();
	void xuat();
	float giatri();
};
typedef struct phanso ps;

void phanso::nhap() {
	cout << "Nhap tu so: "; cin >> ts;
	ms = 0;
	while (ms == 0) {
		cout << "Nhap mau so: ";
		cin >> ms;
	}
}

void phanso::xuat() {
	cout << ts << " / " << ms << endl;
}

float phanso::giatri() {
	float result = (float)ts / (float)ms;
	return result;
}

struct node {
	ps data;
	node* pPrev;
	node* pNext;
};
typedef struct node NODE;

struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void initList(LIST& l) {
	l.pHead = l.pTail = NULL;
}

NODE* taoNode() {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "Khong the cap phat"; return NULL;
	}
	else {
		p->data.nhap();
		p->pNext = NULL;
		p->pPrev = NULL;
		return p;
	}
}

void chenNut(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
		return;
	}
	else {
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
		return;
	}
}

void duyetXuoi(LIST l) {
	for (NODE* i = l.pHead; i != NULL; i = i->pNext) {
		i->data.xuat(); cout << endl;
	}
}

void duyetNguoc(LIST l) {
	for (NODE* i = l.pTail; i != NULL; i = i->pPrev) {
		i->data.xuat(); cout << endl;
	}
}

void nhapList(LIST& l, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap ps thu " << i + 1 << endl;
		NODE* p = taoNode();
		chenNut(l, p);
	}
}

NODE* timMax(LIST l) {
	NODE* MAX = l.pHead;
	for (NODE* i = l.pHead; i != NULL; i = i->pNext) {
		if (i->data.giatri() > MAX->data.giatri()) {
			MAX = i;
		}
	}
	return MAX;
}

NODE* timMin(LIST l) {
	NODE* MIN = l.pHead;
	for (NODE* i = l.pHead; i != NULL; i = i->pNext) {
		if (i->data.giatri() < MIN->data.giatri()) {
			MIN = i;
		}
	}
	return MIN;
}

void xoaDau(LIST &l) {
	if (l.pHead == NULL) {
		cout << "Khong co phan tu de xoa"; 
		return;
	}
	else {
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		l.pHead->pPrev = NULL;
		delete p;
	}
}

void xoaCuoi(LIST& l) {
	if (l.pHead == NULL) {
		cout << "Khong co phan tu de xoa";
		return;
	}
	else {
		NODE* p = l.pTail;
		l.pTail = l.pTail->pPrev;
		l.pTail->pNext = NULL;
		delete p;
	}
}

void xoaTaiK(LIST& l, int k) {
	int count = 0;
	for (NODE* i = l.pHead; i != NULL; i = i->pNext) {
		if (count == k) {
			if (i->pNext == NULL) {
				xoaCuoi(l); return;
			}
			if (i->pPrev == NULL) {
				xoaDau(l); return;
			}
			NODE* p = i;
			NODE* x = i->pNext;
			i = i->pPrev;
			i->pNext = x;
			x->pPrev = i;
			delete p;
			return;
		}
		count++; 
	}
	cout << "Vi tri vuot qua khoang cua danh sach" << endl;
}

void xoaKhiXuatHienX(LIST& l, ps xx) {
	xx.xuat();
	for (NODE* i = l.pHead; i != NULL; i = i->pNext) {
		if (i->data.giatri() == xx.giatri()) {
			if (i->pNext == NULL) {
				xoaCuoi(l); return;
			}
			if (i->pPrev == NULL) {
				xoaDau(l); return;
			}
			NODE* p = i;
			NODE* x = i->pNext;
			i = i->pPrev;
			i->pNext = x;
			x->pPrev = i;
			delete p;
			return;
		}
	}
	cout << "Khong xuat hien phan so trong danh sach" << endl;
}

//-------------------------------------------------------------------


void sapxep(LIST& l) {
	for (NODE* i = l.pHead; i != l.pTail; i = i->pNext) {
		for (NODE* j = i->pNext; j != NULL; j = j->pNext) {
			if (i->data.giatri() < j->data.giatri()) {
				ps temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

bool timKiem(LIST l, ps a) {
	for (NODE* i = l.pHead; i != NULL; i = i->pNext) {
		if (i->data.giatri() == a.giatri()) return true;
	}
	return false;
}

int main() {
	LIST l;
	initList(l);
	cout << "Nhap so phan tu: ";
	int n;
	cin >> n;
	cout << "------------------ NHAP ----------------" << endl;
	nhapList(l, n);
	cout << "----------------- DUYET ------------------" << endl;
	duyetXuoi(l);
	cout << "----------------- TIM PS LON NHAT ------------------" << endl;
	NODE *p = timMax(l); 
	p->data.xuat();
	cout << "------------------TIM PS NHO NHAT -----------------" << endl;
	NODE* p1 = timMin(l);
	p1->data.xuat();
	cout << "--------------------- SAP XEP ---------------------" << endl;
	sapxep(l);
	cout << "Danh sach sau khi sap xep:" << endl;
	duyetXuoi(l);
	return 0;
}
