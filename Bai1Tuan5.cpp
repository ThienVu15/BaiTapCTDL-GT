#include<iostream>
using namespace std;
// Ham swap
void Swap(string &a, string &b){ // Phai dung tham chieu de thay doi gia tri, &a.
	string temp;
	temp = a;
	a = b;
	b = temp;
}
// Nhap vao cac mau 
void Input(string a[],int n){
	for(int i = 0; i<n ; i++){
		cin>>a[i];
	}
}
// Ma hoa cac mau thanh so theo thu tu 1,2,3
void MaHoa(string a[],int n){
	for(int i = 0; i<n ; i++){
		if(a[i] == "trang") a[i] = "2";
		if(a[i] == "do") a[i] = "1";
		if(a[i] == "xanh") a[i] = "3";
	}
}
// Sap xep 
void SapXep(string a[], int n ){
	int i , j , min;
	for(i = 0; i < n ; i++){
		min = i;
		j = i;
	for(j = i + 1 ; j < n; j ++){
		if(a[j] < a[min]) min = j;
	}
	Swap(a[i], a[min]);
	}
}
void Output(string a[],int n){
	for(int i = 0;i<n;i++){
		if(a[i] == "1" ) cout<<"do";
		if(a[i] == "2") cout<<"trang"; 
		if(a[i] == "3") cout<<"xanh";
		if(i<n-1) cout<<",";
	}
}
int main(){
	int n;
    cin >>n;
    if(n<0){
    	cout<<"Khong phai sap xep";
	}
	string a[n];
    Input(a,n);
    MaHoa(a,n);
    SapXep(a,n);
    Output(a,n);
return 0;
}
