#include <iostream>
#include<string>

using namespace std;

//typedef int TypeOfData;

struct SinhVien
{
	string maLop;
	string maSinhVien;
	string tenSinhVien;
	int namSinh;
	string queQuan;
};

typedef SinhVien TypeOfData;

struct TypeOfNode
{
	TypeOfData data;
	struct TypeOfNode *next;
};

typedef struct TypeOfNode *NodePtr;

//// Nhập dữ liệu cho Data
TypeOfData inputTypeOfData()
{
	TypeOfData sinhvien;

	cin.ignore();
	cout << " - Ho ten: ";
	getline(cin, sinhvien.tenSinhVien);

	cout << " - Nam sinh: ";
	cin >> sinhvien.namSinh;

	cin.ignore();
	cout << " - Ma sinh vien: ";
	getline(cin, sinhvien.maSinhVien);

	cin.ignore();
	cout << " - Ma lop: ";
	getline(cin, sinhvien.maLop);

	cin.ignore();
	cout << " - Que quan: ";
	getline(cin, sinhvien.queQuan);

	return sinhvien;
}

///// Khởi tạo
void initialize(NodePtr *L)
{
	*L = NULL;
}

///// Kiểm tra rỗng
int isEmpty(NodePtr L)
{
	return ((L == NULL) ? true : false);
}

///// Tạo một nút
NodePtr CreateNode(TypeOfData data) {
	NodePtr newNode = new TypeOfNode;
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

///// In thông tin của một nút
void printNodeInfo(NodePtr pnode)
{
	cout << " - Ho Ten: " << pnode->data.tenSinhVien << endl;
	cout << " - Nam sinh: " << pnode->data.namSinh << endl;
	cout << " - Ma sinh vien: " << pnode->data.maSinhVien << endl;
	cout << " - Ma lop: " << pnode->data.maLop << endl;
	cout << " - Que quan: " << pnode->data.queQuan << endl;
}

///// Thêm một phần tử vào đầu danh sách
void insertHead(NodePtr *L, TypeOfData data) {
	NodePtr newNode = CreateNode(data);
	if (*L == NULL) {
		*L = newNode;
	}
	else {
		newNode->next = *L;
		*L = newNode;
	}
}

///// Thêm một phần tử vào cuối danh sách
void insertTail(NodePtr *L, TypeOfData data) {
	NodePtr newNode, p;
	newNode = CreateNode(data);
	if (*L == NULL) {
		*L = newNode;
	}
	else {
		p = *L;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
}

///// Thêm một phần tử vào sau một nút trong danh sách
void insertAfter(TypeOfData data, NodePtr p, NodePtr *L)
{
	if (p == NULL)
		cout << "Khong them duoc!" << endl;
	else
	{
		NodePtr q = CreateNode(data);
		q->next = p->next;
		p->next = q;
	}
}

///// Xóa nút p khỏi danh sách L
void deleteList(NodePtr p, NodePtr *L)
{
	if (p == NULL)
		cout << "Phan tu can xoa khong ton tai trong danh sach!" << endl;
	else
	{
		if (isEmpty(*L))
			cout << "Danh sach rong!" << endl;
		else
		{
			if (p == *L)	//p o dau danh sach
			{
				*L = (*L)->next;
			}
			else
			{
				NodePtr q;
				q = *L;
				while (q != NULL && q->next != p)
					q = q->next;
				q->next = p->next;
			}

			p->next = NULL;
			delete p;
		}
	}
}

///// Tìm kiếm theo mã sinh viên
NodePtr searchByMaSinhVien(string maSinhVien, NodePtr L)
{
	if (L == NULL) return NULL;
	else
	{
		NodePtr q;
		q = L;
		while (q != NULL && q->data.maSinhVien.compare(maSinhVien) != 0)
			q = q->next;
		return q;
	}
}

///// Duyệt danh sách
void traverse(NodePtr L)
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
			cout << "Thong tin sinh vien " << ++i << ":" << endl;
			printNodeInfo(q);
			q = q->next;
		}
	}
}

///// Sắp xếp danh sách
void sortListByName(NodePtr *L)
{
	if (*L == NULL)
	{
		cout << "Danh sach rong, khong sap xep!" << endl;
	}
	else
    {
		for (NodePtr p = *L; p->next != NULL; p = p->next)
			for (NodePtr q = p->next; q != NULL; q = q->next)
			{
				if (p->data.tenSinhVien.compare(q->data.tenSinhVien) > 0)
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
	cout << "Nhap so luong Sinh Vien: ";
	cin >> n;

	NodePtr L;
	initialize(&L);

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien " << i + 1 << ":" << endl;

		TypeOfData sinhvien = inputTypeOfData();

		//insertHead(&L, sinhvien);
		insertTail(&L, sinhvien);
	}

	cout << "===> Danh sach sinh vien vua nhap: " << endl;
	traverse(L);

	cout << "==============================================" << endl;
	cout << "			XOA SINH VIEN" << endl;
	string masv;

	cin.ignore();
	cout << "Nhap ma sinh vien de tim kiem: ";
	getline(cin, masv);

	NodePtr found = searchByMaSinhVien(masv, L);
	if (found == NULL) cout << "Khong tim thay sinh vien voi ma " << masv;
	else {
		cout << "Tim thay sinh vien voi ma " << masv << ":" << endl;
		printNodeInfo(found);
		cout << "Xoa sinh vien khoi danh sach ... " << endl;
		deleteList(found, &L);

		cout << "===> Danh sach sinh vien sau khi xoa: " << endl;
		traverse(L);
	}

	cout << "==============================================" << endl;
	cout << "			THEM SINH VIEN" << endl;

	cin.ignore();
	cout << "Nhap ma sinh vien de tim kiem: ";
	getline(cin, masv);
	found = searchByMaSinhVien(masv, L);
	if (found == NULL) cout << "Khong tim thay sinh vien voi ma " << masv;
	else {
		cout << "Tim thay sinh vien voi ma " << masv << ":" << endl;
		printNodeInfo(found);

		cout << "Nhap thong tin sinh vien can them:" << endl;
		TypeOfData sinhvien = inputTypeOfData();

		insertAfter(sinhvien, found, &L);

		cout << "===> Danh sach sinh vien sau khi THEM: " << endl;
		traverse(L);
	}

	cout << "==============================================" << endl;
	cout << "			SAP XEP DANH SACH" << endl;
	sortListByName(&L);
	cout << "===> Danh sach sinh vien sau khi SAP XEP: " << endl;
	traverse(L);
}
