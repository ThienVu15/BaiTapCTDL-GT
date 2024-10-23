#include<iostream>
using namespace std;
struct Nam{
	int NamSinh;
	int SoNguoi;
};
// Tim  so nguoi sinh ra nhieu nhat va sinh ra so nguoi it nhat 
void NamMaxMin(Nam Ds[], int n){
	if(n == 0) return;
	int Max = Ds[0].SoNguoi;
	int Min = Ds[0].SoNguoi;
	for(int i = 1; i < n ; i++){
		if(Ds[i].SoNguoi>Max) Max = Ds[i].SoNguoi;
		if(Ds[i].SoNguoi<Min) Min = Ds[i].SoNguoi;
	}
		cout<<"Nam co so nguoi sinh nhieu nhat la:";
	for(int i = 0; i < n ; i++){
		if(Ds[i].SoNguoi == Max) 
		 cout<< Ds[i].NamSinh << "  "<<Ds[i].SoNguoi<< " nguoi " ;
	}
	    cout<<"\n";
		cout<<"Nam co so nguoi sinh it nhat la: ";
	for(int i = 0; i < n ; i++){
		if(Ds[i].SoNguoi == Min) 
		 cout<< Ds[i].NamSinh << "  "<<Ds[i].SoNguoi<<" nguoi ";
	}
	cout<<"\n";
}


// Tim cac nam co so nguoi sinh bang nhau 
void NamCung(Nam Ds[], int n){
	bool DaIn[n] = {false}; // MAng de bo qua nhung nam da in
	for(int i = 0; i < n; i++ ){
		if(DaIn[i]) continue;
		bool Check = false;
		for(int j= i+1; j < n ; j++ ){
			if(Ds[i].SoNguoi == Ds[j].SoNguoi) {
			       if(!Check){
			       	cout<< "Cac nam "<<Ds[i].NamSinh;
			       	Check = true;
				   }
				   cout<<","<< Ds[j].NamSinh;
				   DaIn[j]=true;
				   
			}
			}
			if(Check){
				cout<<"co cung so nguoi sinh la: "<<Ds[i].SoNguoi<<endl;
			}
		
	}
	}

int main(){
	Nam Ds[51] = {
    {1920, 19},
    {1921, 77},
    {1922, 40},
    {1923, 90},
    {1924, 2},
    {1925, 25},
    {1926, 54},
    {1927, 17},
    {1928, 79},
    {1929, 6},
    {1930, 44},
    {1931, 24},
    {1932, 14},
    {1933, 4},
    {1934, 95},
    {1935, 47},
    {1936, 66},
    {1937, 48},
    {1938, 23},
    {1939, 98},
    {1940, 15},
    {1941, 86},
    {1942, 25},
    {1943, 50},
    {1944, 9},
    {1945, 29},
    {1946, 64},
    {1947, 3},
    {1948, 67},
    {1949, 4},
    {1950, 90},
    {1951, 81},
    {1952, 74},
    {1953, 34},
    {1954, 98},
    {1955, 13},
    {1956, 87},
    {1957, 96},
    {1958, 56},
    {1959, 90},
    {1960, 49},
    {1961, 85},
    {1962, 94},
    {1963, 66},
    {1964, 19},
    {1965, 95},
    {1966, 47},
    {1967, 42},
    {1968, 65},
    {1969, 87},
    {1970, 11}
};
	int n = 51;
	NamMaxMin(Ds,n);
	NamCung(Ds,n);
	
}










