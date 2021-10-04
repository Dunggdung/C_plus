//5. Cho dãy số nguyên.Viết chương trình kiểm tra mảng có tăng dần hay không ?
#include<iostream>
using namespace std;
// +, -, * ,/ ,+=,-=,*=,/=,<,==,<=,>=,++,-- (2TH),=
class PhanSo {
private:
    int tu, mau;
public:
    friend istream& operator >>(istream& is, PhanSo& ps);
    friend ostream& operator <<(ostream& os, const PhanSo& ps);
    PhanSo operator + (PhanSo ps);
    PhanSo operator - (PhanSo ps);
    PhanSo operator * (PhanSo ps);
    PhanSo operator / (PhanSo ps);
    PhanSo operator += (PhanSo ps);
    //PhanSo cong (PhanSo ps);
    int operator > (PhanSo ps);
};
istream& operator >>(istream& is, PhanSo& ps) {
    cout << "Nhap tu: ";
    is >> ps.tu;
    cout << "Nhap mau: ";
    is >> ps.mau;
    return is;
}
ostream& operator <<(ostream& os, const PhanSo& ps) {
    os << ps.tu << "/" << ps.mau << endl;
    return os;
}
//void PhanSo::xuat() {
//    cout << tu << "/" << mau << endl;
//}
PhanSo PhanSo::operator + (PhanSo ps) {
    PhanSo t;
    t.tu = tu * ps.mau +  mau * ps.tu;
    t.mau = mau * ps.mau;
    return t;
}
PhanSo PhanSo::operator - (PhanSo ps){
    PhanSo t;
    t.tu = tu * ps.mau -  mau * ps.tu;
    t.mau = mau * ps.mau;
    return t;
}
PhanSo PhanSo::operator * (PhanSo ps){
    PhanSo t;
    t.tu = tu * ps.tu ;
    t.mau = mau * ps.mau;
    return t;
}
PhanSo PhanSo:: operator / (PhanSo ps){
    PhanSo t;
    t.tu = tu * ps.mau ;
    t.mau = mau * ps.tu;
    return t;
}
PhanSo PhanSo::operator += (PhanSo ps){
    tu = tu * ps.mau +  mau * ps.tu;
    mau = mau * ps.mau;
    return *this;
} 
PhanSo PhanSo:: operator ++(){
    tu = tu + mau;
    return *this;
}
int PhanSo::operator > (PhanSo ps) {
    if ((tu / mau) > (ps.tu / ps.mau)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    PhanSo a, b,c,d,e,f;
    PhanSo c1,d1,e1,f1;
    cout << "nhap phan so a : " << endl;
    cin >> a;
    cout << "nhap phan so b : " << endl;
    cin >> b;
    cout << "phan so da nhap vao la: " << endl;
    cout << a;//a.xuat();
    cout << b;
    cout <<"Phep cong tru nhan chia lan luot la: " << endl;
    c = a + b;//c= a.cong(b);
    cout << c;
    d = a - b;
    cout << d;
    e = a * b;
    cout << e;
    f = a / b;
    cout << f;
    cout << "Phep cong tru nhan chia toan tu lan luot la: " << endl;
    c1 = a += b;
    cout << c1;
        if (a > b) {
        cout << "Lon hon";
    }
    else {
        cout << "be hon hoac bang ";
    }
}