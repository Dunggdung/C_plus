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
        friend bool operator >= (PhanSo a,PhanSo b);
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
bool operator >= (PhanSo a,PhanSo b) {
    return (float)(a.tu/a.mau) >= (b.tu/b.mau);
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
void sosanh(PhanSo a, PhanSo b){
    if (a >= b){
        cout << "Hai Phan So Lon Hon Hoac Bang"<<endl;
    }else {
        cout << "Phan So Dau Nho Hon Phan So Sau"<<endl;
    }
}
// phan so lơn nhat phan so be nhat mang co 5 phan so 
void Lon_BeNhat(PhanSo a[], int n){
    for(int i=0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            if (a[i] >= a[j]){
                swap (a[i], a[j]);
            }
        }
    }
    cout <<"Phan So Lon Nhat: " << a[4] << endl;
    cout <<"Phan So Nho Nhat: " << a[0] << endl;
}
int main (){
    PhanSo ps1,ps2;
    cout <<"Phan So 1: "<<endl;
    cin >> ps1;
    cout <<"Phan So 2: "<<endl;
    cin >> ps2;
    cout << ps1 << ps2 << endl;
    sosanh(ps1,ps2);
    PhanSo ps[5];
    input(ps,5);
    output(ps,5);
    Lon_BeNhat(ps,5);
    return 0;
}