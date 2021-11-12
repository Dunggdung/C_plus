//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;
class PhanSo {
    private:
        float tu;
        float mau;
    public:
        PhanSo();
        friend istream& operator>>(istream& is,PhanSo& ps);
        friend ostream& operator<<(ostream& os,PhanSo ps);
        bool operator > (PhanSo ps1);
};
//hàm thiết lập
PhanSo::PhanSo(){
    tu = 0;
    mau = 1;
}
// toán tử nhập 
istream& operator>>(istream& is,PhanSo& ps){
    cout<<" Nhap Tu: ";
    is >> ps.tu;
    do {
        cout<<" Nhap Mau: ";
        is >> ps.mau;
        if (ps.mau == 0){
            cout<<" Mau khong duoc bang = 0!"<<endl;
            cout<<" Nhap Mau: ";
            is >> ps.mau;
        }
    }while(ps.mau == 0);
    return is;
}
//toan tử xuat
ostream& operator<<(ostream& os,PhanSo ps){
    os <<ps.tu<<"/"<<ps.mau<<endl;
    return os;
}
//toan tử so sánh phan so >
bool PhanSo::operator >(PhanSo ps1){
    return (float)(this->tu/this->mau) > (ps1.tu/ps1.mau);
}
//Nhâp nhiều phân số
void input(PhanSo a[], int n){
    for(int i=0; i<n; i++){
        cout <<"Nhap Phan So " << i+1 << endl ;
        cin >> a[i] ;
    } 
}
// xuất nhìu phân số
void output(PhanSo a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"Phan so " << i+1 << ": " ;
        cout << a[i] ;
    }
}
// sắp xếp phân số tăng dàn
void sapxep(PhanSo a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
int main (){
    int n ;
    cout <<"Nhap so luong phan so: ";
    cin >> n;
    PhanSo ps[n];
    input(ps,n);
    output(ps,n);
    cout <<endl<<"Day phan so sap xep tang dan";
    sapxep(ps,n);
    output(ps,n);
    return 0;
}