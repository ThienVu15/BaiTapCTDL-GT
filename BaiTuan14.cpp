#include <iostream>
#include <string>
using namespace std;

// Dinh nghia cau truc cay
struct Node {
    string value;
    Node* left;
    Node* right;

    Node(string val) : value(val), left(NULL), right(NULL) {}
};

// Ham tao nut
Node* createNode(string value) {
    return new Node(value);
}

// Cac ham duyet cay
void printInfix(Node* root) {
    if (!root) return;
    if (root->left) cout << "(";
    printInfix(root->left);
    cout << root->value;
    printInfix(root->right);
    if (root->right) cout << ")";
}

void printPostfix(Node* root) {
    if (!root) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->value << " ";
}

void printPrefix(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Tao cay bieu thuc
Node* buildExpressionTree() {
    // Cac toan tu va toan hang
    Node* plus = createNode("+");
    Node* minus = createNode("-");
    Node* mult1 = createNode("*");
    Node* mult2 = createNode("*");
    Node* divide = createNode("/");
    Node* power1 = createNode("^");
    Node* power2 = createNode("^");

    // Cac toan hang
    Node* a = createNode("a");
    Node* b = createNode("b");
    Node* c = createNode("c");
    Node* d = createNode("d");
    Node* e = createNode("e");
    Node* f = createNode("f");
    Node* h = createNode("h");
    Node* five = createNode("5");
    Node* six = createNode("6");
    Node* one = createNode("1");
    Node* two = createNode("2");

    // Xay dung cay
    power1->left = c;
    power1->right = six;

    divide->left = b;
    divide->right = power1;

    mult1->left = five;
    mult1->right = divide;

    minus->left = a;
    minus->right = mult1;

    power2->left = e;
    power2->right = one;

    mult2->left = createNode("-");
    mult2->left->left = h;
    mult2->left->right = f;

    mult2->right = power2;

    divide->left = mult2;
    divide->right = two;

    plus->left = minus;
    plus->right = divide;

    return plus;
}

int main() {
    Node* root = buildExpressionTree();

    cout << "Infix: ";
    printInfix(root);
    cout << "\n";

    cout << "Postfix: ";
    printPostfix(root);
    cout << "\n";

    cout << "Prefix: ";
    printPrefix(root);
    cout << "\n";

    return 0;
}

