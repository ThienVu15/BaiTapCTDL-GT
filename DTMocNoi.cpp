#include<iostream>
using namespace std;

struct Node{
	float heso;
	int somu;
	Node* next;
};
struct ListDT{ 
	Node* first;
	Node* last;
};
// Khoi tao mot danh sach da thuc 
void KtaoDT(ListDT *l){
	l->first = l->last = NULL;
}
// Tao mot node moi
Node* makeNode(float hs, int sm){
	Node* p = new Node(); // Cap phat dong bo nho moi cho Node va tro p toi dia chi NULL
	if( p == NULL ) return NULL;
	p->heso = hs;
	p->somu = sm;
	p->next = NULL;
	return p;
}
// Them node p vao danh sach 
void addNode(ListDT* lDT, Node *p){
	// DSDT chua co gi
	if(lDT->first == NULL){
		lDT->first = lDT->last = p;
	} 
	else{
		lDT->last->next = p; // gan dia chi nut cuoi hien tai tro toi p thi node cuoi thay doi thanh node p
		lDT->last = p; // cap nhat nut cuoi thanh node p
			
	}
}
// Them node vao danh sach voi he so va so mu cho truoc  
void attachNode(ListDT* lDT, float heso , int mu){
	Node* pDT = makeNode(heso,mu);
	if(pDT == NULL) return;
	addNode(lDT, pDT);
}
// Ham nhap da thuc 
void NhapDaThuc(ListDT* lDT){
	float heso;
	int mu;
	int i = 0; // Dem so phan tu 
	cout<< "Nhap da thuc va he so neu bang 0 thi dung lai: \n ";
	do{
		i++;
		cout<<"Nhap so cua phan tu thu: "<<i<< endl;
		cout<<"He so la: "; cin>>heso;
		if(heso == 0) break;
		cout<<"So mu la: "; cin>>mu;
		attachNode(lDT, heso,mu);
	} while(heso != 0);
}
void inDaThuc(ListDT lDT){
	Node* p;
	p=lDT.first;
	cout<<"\n f(x) = ";
	while(p != NULL){
		if(p->heso == 1){
		cout<<"x^"<<p->somu;
		if(p->next!= NULL && p->heso!=0) cout<<"+";
		}
		else{
			cout<< p->heso <<"*x^"<<p->somu;
		if(p->next!= NULL && p->heso!=0) cout<<"+";
		}
		p=p->next;
	}
}
int main(){
	ListDT fx;
	KtaoDT(&fx);
	NhapDaThuc(&fx);
	inDaThuc(fx);
	return 0;
}



