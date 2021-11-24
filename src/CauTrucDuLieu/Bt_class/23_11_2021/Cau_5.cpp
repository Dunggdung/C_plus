#include <iostream>
using namespace std;

class Sach{
    private:
        string Ten;
        int Trang;
    public:
        Sach();
        Sach(Sach *c){
            this->Ten = c->Ten;
            this->Trang = c->Trang;
        }
        void Nhap();
        void Xuat();
        string getTen(){
            return Ten;
        }
        int getTrang(){
            return Trang;
        }
        void SortBook(int n);
        void SortPage(int n);
};
Sach::Sach(){
    Ten = "";
    Trang = 0;
}
void Sach::Nhap(){
    fflush(stdin);
    cout << "Nhap Ten Sach: ";
    getline(cin, Ten);
    cout << "Nhap So Trang: " ;
    cin >> Trang;
}
void Sach::Xuat(){
    cout <<" ||Ten: "<<Ten<< " ||So Trang: "<<Trang<<endl;
}

void swap(Sach &a, Sach &b){
    Sach temp;
    temp = a;
    a = b; 
    b = temp;
}
void Sach:: SortBook(int n){
    Sach *a;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j < n; j++){
            if((a+i)->getTen() < (a+j)->getTen()){
				swap(a[i], a[j]);
            }
        }
    }
}
void Sach:: SortPage(int n){
    Sach *a;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j < n; j++){
            if((a+i)->getTrang() > (a+j)->getTrang()){
               swap(*(a+i), *(a+j));
            }
        }
    }
}
int main (){
    Sach *a;
    int n = 3;
    a = new Sach[n];
    cout <<endl<< "NHAP THONG TIN SACH"<<endl;
    for (int i=0; i < n; i++){
        cout <<"SACH "<<i+1<<endl;
        (a+i)->Nhap();
    }

    for (int i=0; i < n; i++){
        cout <<"STT: "<<i+1;
        (a+i)->Xuat();
    }
    // a->SortBook(n);
    cout <<endl<<"Danh Sach Sap Xep Theo Tang Dan Ten"<<endl;
    for (int i=0; i < n; i++){
        cout <<"STT: "<<i+1;
        (a+i)->Xuat();
    }
    a->SortPage(n);
    cout <<endl<<"Danh Sach Sap Xep Theo So Luong Trang Giam Dan"<<endl;
    for (int i=0; i < n; i++){
        cout <<"STT: "<<i+1;
        (a+i)->Xuat();
    }
    return 0;
}