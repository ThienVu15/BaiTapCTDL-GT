#include<iostream>
#include<string>
using namespace std;

struct Node {
    string name;  // Ten cua sach, chuong, muc
    int page;     // So trang bat dau cua muc do
    Node* child;  // Con dau tien
    Node* sibling; // Anh chi em cung bac trong mot chuong
};

// Them mot muc vao sach
Node* add(Node* parent, const string& name, int page) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->page = page;
    newNode->child = NULL;
    newNode->sibling = NULL;

    if (parent->child == NULL) {
        parent->child = newNode;
    } else {
        Node* temp = parent->child;
        while (temp->sibling != NULL) {
            temp = temp->sibling;
        }
        temp->sibling = newNode;
    }
    return newNode;  // Tra ve con node vua them
}

// Tinh tong so trang trong mot chuong
int TotalPage(Node* chapter) {
    int sum = 0;
    Node* temp = chapter->child;
    while (temp) {
        sum += temp->page;
        temp = temp->sibling;
    }
    return sum;
}

// Tim chuong dai nhat
Node* FindLongestChapter(Node* root) {
    Node* temp = root->child;
    Node* LongestChapter = NULL;
    int maxPage = 0;
    while (temp) {
        int totalPage = TotalPage(temp);
        if (totalPage > maxPage) {
            maxPage = totalPage;
            LongestChapter = temp;
        }
        temp = temp->sibling;
    }
    return LongestChapter;
}

// Tim mot muc theo ten
Node* Find(Node* root, const string& name) {
    Node* temp = root->child;
    while (temp) {
        if (temp->name == name) {
            return temp;
        }
        Node* childchild = Find(temp, name);
        if (childchild) return childchild;
        temp = temp->sibling;
    }
    return NULL;
}

// Xoa mot muc
void DeleteNode(Node* parent, const string& name) {
    Node* temp = parent->child;
    Node* prev = NULL;
    while (temp) {
        if (temp->name == name) {
            if (prev) {
                prev->sibling = temp->sibling;
            } else {
                parent->child = temp->sibling;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->sibling;
    }
}

int main() {
    Node* root = new Node;
    root->child = NULL;  // Khoi tao con cua root la NULL

    // Them chuong 1
    Node* chapter1 = add(root, "Chuong 1: Sap xep", 1);
    add(chapter1, "1, SelectionSort", 3);
    add(chapter1, "1.1 Cai dat SelectionSort", 10);
    add(chapter1, "2, InsertionSort", 15);

    // Them chuong 2
    Node* chapter2 = add(root, "Chuong 2: Cay", 32);
    add(chapter2, "1, Khai niem cay", 33);
    add(chapter2, "1.1 Cay nhi phan", 35);
    add(chapter2, "Cay AVL", 40);

    // So chuong cua sach
    int NumberOfChapter = 0;
    Node* temp = root->child;
    while (temp) {
        NumberOfChapter++;
        temp = temp->sibling;
    }
    cout << "So chuong cua sach la: " << NumberOfChapter << endl;

    // Chuong dai nhat
    Node* longestChapter = FindLongestChapter(root);
    cout << "Chuong dai nhat la: " << longestChapter->name;
    cout << " voi so trang la: " << TotalPage(longestChapter) << endl;

    // Tim mot muc
    Node* findMuc = Find(root, "Cay AVL");
    if (findMuc) {
        cout << "Muc " << findMuc->name << " o trang so " << findMuc->page << endl;
    }

    // Xoa mot muc
    string mucXoa = "1, SelectionSort";
    cout << "Xoa muc: " << mucXoa << endl;
    DeleteNode(root, mucXoa);

    // Cap nhat lai so chuong sau khi xoa
    NumberOfChapter = 0;  // Cap nhat lai so chuong
    temp = root->child;
    while (temp) {
        NumberOfChapter++;
        temp = temp->sibling;
    }
    cout << "Cap nhat lai so chuong sau khi xoa la: " << NumberOfChapter << endl;

    // In thong tin sau khi xoa
    temp = root->child;
    while (temp) {
        cout << temp->name << " So trang con la: " << TotalPage(temp) << endl;
        temp = temp->sibling;
    }

    return 0;
}

