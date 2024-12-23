#include<iostream>
using namespace std;
struct Node{
	int key;
	Node* left;
	Node* right;
	int height;
	// Ham khoi tao
	Node(int k){
		key = k;
		left = NULL;
		right = NULL;
		height = 0; // chieu cao cua nut khi moi tao
	}	
};
// Ham lay chieu cao cua node
int getHeight(Node* node){
	return node ? node->height : -1; // cay rong co chieu cao la -1
}
// ham lay can bang cua node
int getBlance(Node* node){
	return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
// Ham tim max
int max(int a, int b){
	return(a>b) ? a : b;
}
// Quay trai 
Node* rotateLeft(Node* y){
	Node *x = y->right;
	Node *T2 = x->left;
	x->left = y;
	y->right = T2;
	// cap nhat lai chieu cao sau khi quay
	y->height = max(getHeight(y->left),getHeight(y->right));
	x->height = max(getHeight(x->left),getHeight(y->right));
	// chuyen cha
	return x;
}
// Quay phai
Node* rotateRight(Node* x){
	Node* y = x->left;
	Node* T2 = y->right;
	y->right = x;
	x->left = T2;
	// cap nhat lai chieu cao sau khi quay
	x->height = max(getHeight(x->left),getHeight(x->right));
	y->height = max(getHeight(y->left),getHeight(y->right));
	// chuyen cha
	return y;
}
Node* Insert(Node* node, int key){
	if(!node){
		return new Node(key);
	}
	if(key < node->key){
		node->left = Insert(node->left,key);
	}
	else if(key>node->key){
		node->right = Insert(node->right,key);
	}
	else return node; // khong chap nhan gia tri trung 
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	int blance = getBlance(node);
	// quay phai
	if(blance > 1 && key < node->left->key) return rotateRight(node);
	// quay trai
	if(blance < -1 && key > node->right->key) return rotateLeft(node);
	// quay trai phai 
	if(blance > 1 && key > node->left->key) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	// quay phai trai
	if(blance < -1 && key < node->right->key){
		node->right = rotateRight((node->right));
		return rotateLeft(node);
	}	
	return node;
}
// In theo thu tu trung to 
void inOrder(Node* root){
	if(root){
		inOrder(root->left);
		cout<<root->key<<" ";
		inOrder(root->right);
	}
}

int main(){
	Node* root = NULL;
	// mang tren lop la
	int A[] = {17,23,201,98,67,83,13,23,10,191,84,58};
	int n = sizeof(A)/sizeof(A[0]);
	// chen cac so trong mang
	for(int i = 0; i < n; i++){
		root = Insert(root,A[i]);
	}
	inOrder(root);
	return 0;
}


