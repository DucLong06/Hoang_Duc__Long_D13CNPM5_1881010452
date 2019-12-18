//#include "pch.h"

#include <iostream>
#include<string>

using namespace std;

struct NhanVien
{
	string maNhanVien;
	string tenNhanVien;
	int namSinh;
	float heSoLuong;
};

typedef NhanVien TypeOfData;

struct TypeOfNode
{
	TypeOfData data;
	struct TypeOfNode *next;
	struct TypeOfNode *prev;
};

typedef struct TypeOfNode *NodePtr;

TypeOfData inputTypeOfData()
{
	TypeOfData nhanvien;

	cin.ignore();
	cout << " - Ho ten: ";
	getline(cin, nhanvien.tenNhanVien);

	cout << " - Nam sinh: ";
	cin >> nhanvien.namSinh;

	cin.ignore();
	cout << " - Ma nhan vien: ";
	getline(cin, nhanvien.maNhanVien);

	cout << " - He so luong: ";
	cin >> nhanvien.heSoLuong;

	return nhanvien;
}

///// Khởi tạo
void initialize(NodePtr *L, NodePtr *R)
{
	*L = NULL;
	*R = NULL;
}

///// Kiểm tra rỗng
int isEmpty(NodePtr L, NodePtr R)
{
	return ((L == NULL || R == NULL) ? true : false);
}

///// Tạo một nút
NodePtr CreateNode(TypeOfData data) {
	NodePtr newNode = new TypeOfNode;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = data;
	return newNode;
}

///// In thông tin của một nút
void printNodeInfo(NodePtr pnode)
{
	cout << " - Ho Ten: " << pnode->data.tenNhanVien << endl;
	cout << " - Nam sinh: " << pnode->data.namSinh << endl;
	cout << " - Ma nhan vien: " << pnode->data.maNhanVien << endl;
	cout << " - He so luong: " << pnode->data.heSoLuong << endl;
}

///// Thêm một phần tử vào đầu danh sách
void insertHead(NodePtr *L, NodePtr *R, TypeOfData data) {
	NodePtr newNode = CreateNode(data);
	if (*L == NULL) {
		*L = newNode;
		*R = newNode;
		return;
	}
	(*L)->prev = newNode;
	newNode->next = *L;
	*L = newNode;
}

///// Thêm một phần tử vào cuối danh sách
void insertTail(NodePtr *L, NodePtr *R, TypeOfData data) {
	NodePtr newNode = CreateNode(data);
	if (*L == NULL) {
		*L = newNode;
		*R = newNode;
		return;
	}
	(*R)->next = newNode;
	newNode->prev = *R;
	*R = newNode;
}

///// Thêm một phần tử vào sau một nút trong danh sách
void insertAfter(TypeOfData data, NodePtr p, NodePtr *L, NodePtr *R)
{
	if (p == NULL)
		cout << "Khong them duoc!" << endl;
	else
	{
		NodePtr q = CreateNode(data);
		
		if (*L == NULL && *R == NULL) {
			insertHead(L, R, data);
			return;
		}
		else if (p == *R)
		{
			insertTail(L, R, data);
			return;
		}
		else
		{
			q->prev = p;
			q->next = p->next;
			p->next->prev = q;
			p->next = q;
		}
	}
}

void deleteAtHead(NodePtr *L)
{
	if (*L == NULL)
	{
		return;
	}
	*L = (*L)->next;
	(*L)->prev = NULL;
}

void deleteAtTail(NodePtr *R)
{
	if (*R == NULL) {
		return;
	}
	*R = (*R)->prev;
	(*R)->next = NULL;
}

///// Xóa nút p khỏi danh sách L
void deleteList(NodePtr p, NodePtr *L, NodePtr *R)
{
	if (p == NULL)
		cout << "Phan tu can xoa khong ton tai trong danh sach!" << endl;
	else
	{
		if (isEmpty(*L, *R))
			cout << "Danh sach rong!" << endl;
		else
		{
			if (*L == *R && p == *L)
			{
				*L = NULL;
				*R = NULL;
			}
			else if (p == *L)
			{
				*L = (*L)->next;
				(*L)->prev = NULL;
				p->next = NULL;
			}
			else if (p == *R)
			{
				*R = (*R)->prev;
				(*R)->next = NULL;
				p->prev = NULL;
			}
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				p->next = NULL;
				p->prev = NULL;
			}
			delete p;
		}
	}
}

///// Tìm kiếm theo mã nhan viên
NodePtr searchFromHeadByMaNhanVien(string maNhanVien, NodePtr L)
{
	if (L == NULL) return NULL;
	else
	{
		NodePtr q;
		q = L;
		while (q != NULL && q->data.maNhanVien.compare(maNhanVien) != 0)
			q = q->next;
		return q;
	}
}

///// Tìm kiếm theo mã nhan viên
NodePtr searchFromTailByMaNhanVien(string maNhanVien, NodePtr R)
{
	if (R == NULL) return NULL;
	else
	{
		NodePtr q;
		q = R;
		while (q != NULL && q->data.maNhanVien.compare(maNhanVien) != 0)
			q = q->prev;
		return q;
	}
}

///// Duyệt danh sách từ đầu
void traverseFromHead(NodePtr L)
{
	if (L == NULL)
		cout << "Danh sach rong!\n";
	else
	{
		NodePtr q;
		q = L;
		int i = 0;
		while (q != NULL)
		{
			/////In thong tin sinh vien:
			cout << "Thong tin nhan vien " << ++i << ":" << endl;
			printNodeInfo(q);
			q = q->next;
		}
	}
}

///// Duyệt danh sách từ cuối
void traverseFromTail(NodePtr R)
{
	if (R == NULL)
		cout << "Danh sach rong!\n";
	else
	{
		NodePtr q;
		q = R;
		int i = 0;
		while (q != NULL)
		{
			/////In thong tin sinh vien:
			cout << "Thong tin nhan vien " << ++i << ":" << endl;
			printNodeInfo(q);
			q = q->prev;
		}
	}
}

///// Sắp xếp danh sách tăng dần theo tên bằng cách duyệt danh sách từ ĐẦU
void sortListByNameFromHead(NodePtr *L)
{
	if (*L == NULL)
	{
		cout << "Danh sach rong, khong sap xep!" << endl;
	}
	else {
		for (NodePtr p = *L; p->next != NULL; p = p->next)
			for (NodePtr q = p->next; q != NULL; q = q->next)
			{
				if (p->data.tenNhanVien.compare(q->data.tenNhanVien) > 0)
				{
					TypeOfData data = p->data;
					p->data = q->data;
					q->data = data;
				}
			}
	}
}

///// Sắp xếp danh sách tăng dần theo tên bằng cách duyệt danh sách từ CUỐI
void sortListByNameFromTail(NodePtr *R)
{
	if (*R == NULL)
	{
		cout << "Danh sach rong, khong sap xep!" << endl;
	}
	else {
		for (NodePtr p = *R; p->prev != NULL; p = p->prev)
			for (NodePtr q = p->prev; q != NULL; q = q->prev)
			{
				if (p->data.tenNhanVien.compare(q->data.tenNhanVien) < 0)
				{
					TypeOfData data = p->data;
					p->data = q->data;
					q->data = data;
				}
			}
	}
}

int main()
{
	int n;
	cout << "Nhap so luong Nhan Vien: ";
	cin >> n;

	NodePtr L, R;
	initialize(&L, &R);

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;

		TypeOfData nhanvien = inputTypeOfData();

		//insertHead(&L, &R, nhanvien);
		insertTail(&L, &R, nhanvien);
	}

	cout << "===> Danh sach sinh vien vua nhap XUOI: " << endl;
	traverseFromHead(L);

	cout << "===> Danh sach sinh vien vua nhap NGUOC: " << endl;
	traverseFromTail(R);

	string manv;
	NodePtr found;

	cout << "==============================================" << endl;
	cout << "			XOA NHAN VIEN" << endl;

	cin.ignore();
	cout << "Nhap ma nhan vien de tim kiem: ";
	getline(cin, manv);

	found = searchFromHeadByMaNhanVien(manv, L);
	if (found == NULL) cout << "Khong tim thay nhan vien voi ma " << manv;
	else {
		cout << "Tim nhan nhan vien voi ma " << manv << ":" << endl;
		printNodeInfo(found);
		cout << "Xoa nhan vien khoi danh sach ... " << endl;
		deleteList(found, &L, &R);

		cout << "===> Danh sach nhan vien sau khi xoa: " << endl;
		traverseFromHead(L);
	}

	cout << "==============================================" << endl;
	cout << "			THEM NHAN VIEN" << endl;

	cin.ignore();
	cout << "Nhap ma nhan vien de tim kiem: ";
	getline(cin, manv);
	found = searchFromTailByMaNhanVien(manv, R);
	if (found == NULL) cout << "Khong tim thay nhan vien voi ma " << manv;
	else {
		cout << "Tim thay nhan vien voi ma " << manv << ":" << endl;
		printNodeInfo(found);

		cout << "Nhap thong tin nhan vien can them, sau nhan vien: " << found->data.tenNhanVien << ": " << endl;
		TypeOfData sinhvien = inputTypeOfData();

		insertAfter(sinhvien, found, &L, &R);

		cout << "===> Danh sach nhan vien sau khi THEM - XUOI:" << endl;
		traverseFromHead(L);

		cout << "===> Danh sach nhan vien sau khi THEM - NGUOC:" << endl;
		traverseFromTail(R);
	}

	cout << "==============================================" << endl;
	cout << "			SAP XEP DANH SACH" << endl;
	
	sortListByNameFromHead(&L);
	//sortListByNameFromTail(&R);

	cout << "===> Danh sach nhan vien sau khi SAP XEP - XUOI:" << endl;
	traverseFromHead(L);

	cout << "===> Danh sach nhan vien sau khi SAP XEP - NGUOC:" << endl;
	traverseFromTail(R);
}