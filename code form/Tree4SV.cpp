//#include "pch.h"

#include <iostream>
#include<string>

using namespace std;

typedef int TypeOfData;

TypeOfData inputTypeOfData()
{
	TypeOfData data;

	cout << " - Data: ";
	cin >> data;

	return data;
}

struct TypeOfNode
{
	TypeOfData data;
	struct TypeOfNode *left;
	struct TypeOfNode *right;
};

typedef struct TypeOfNode *BinaryTree;
typedef struct TypeOfNode *NodePtr;

///// In thông tin của một nút
void printNodeInfo(NodePtr pnode)
{
	//cout << " - Data: " << pnode->data << endl;
	cout << pnode->data << " ";
}

///// Khởi tạo
void initialize(BinaryTree &T)
{
	T = NULL;
}

///// Tạo một nút
NodePtr createNode(TypeOfData data) {
	NodePtr newNode = new TypeOfNode;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void preOrder(BinaryTree T)
{
	if (T != NULL)
	{
		printNodeInfo(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(BinaryTree T)
{
	if (T != NULL)
	{
		inOrder(T->left);
		printNodeInfo(T);
		inOrder(T->right);
	}
}

void postOrder(BinaryTree T)
{
	if (T != NULL)
	{
		postOrder(T->left);
		postOrder(T->right);
		printNodeInfo(T);
	}
}

NodePtr search(TypeOfData data, BinaryTree T)
{
	NodePtr p;
	p = T;
	if (p != NULL)
	{
		if (data < p->data)
			return search(data, p->left);
		else if (data > p->data)
			return search(data, p->right);
		else return p;
	}
	else return NULL;
}

void insertToTree(BinaryTree &T, TypeOfData data)
{
	NodePtr q;
	if (T == NULL)
	{
		q = createNode(data);
		T = q;
	}
	else if (data < T->data)
		insertToTree(T->left, data);
	else if (data > T->data)
		insertToTree(T->right, data);
}

void deleteFromTree(BinaryTree &T, TypeOfData data)
{
	if (T == NULL) return;
	if (data < T->data)
		deleteFromTree(T->left, data);
	else if (data > T->data)
		deleteFromTree(T->right, data);
	else
	{
		NodePtr q;
		if (T->left == NULL)
		{
			q = T;
			T = T->right;
			delete q;
		}
		else if (T->right == NULL)
		{
			q = T;
			T = T->left;
			delete q;
		}
		else
		{
			NodePtr p = T->right;
			while (p->left != NULL)
				p = p->left;
			T->data = p->data;
			deleteFromTree(T->right, T->data);
		}
	}
}

void test_main()
{
	int n;
	cout << "Nhap so luong du lieu: ";
	cin >> n;

	BinaryTree T;
	initialize(T);

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin du lieu " << i + 1 << ":" << endl;

		TypeOfData data = inputTypeOfData();

		insertToTree(T, data);
	}

	cout << "===> Danh sach du lieu vua nhap (PreOder): " << endl;
	preOrder(T);

	cout << endl << "===> Danh sach du lieu vua nhap (InOder): " << endl;
	inOrder(T);

	cout << endl << "===> Danh sach du lieu vua nhap (PostOder): " << endl;
	postOrder(T);

	TypeOfData data;
	NodePtr found;

	cout << "==============================================" << endl;
	cout << "			XOA DATA" << endl;

	cin.ignore();
	cout << "Nhap data de tim kiem: ";
	cin >> data;

	found = search(data, T);
	if (found == NULL) cout << "Khong tim thay du lieu " << data;
	else {
		cout << "Tim thây du lieu " << data << ":" << endl;
		printNodeInfo(found);
		cout << "Xoa du lieu khoi cay ... " << endl;

		deleteFromTree(T, data);

		cout << "===> Danh sach du lieu sau khi xoa (PreOrder): " << endl;
		preOrder(T);
	}
}

int main()
{
	test_main();

	getchar();
}
