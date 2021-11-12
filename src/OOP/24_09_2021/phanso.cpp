// nhap xuat cong , tru , nhan , chia , rut gon , so sanh
// 1/2 + 1/2 = 
// 10/12 -> 5/6
//4/8 -> 1/2
#include "iostream";
#include <math.h>;
using namespace std;
class PhanSo 
{
private:
    int tu, mau;
public:
    void nhap();//1 ngoi không cần truyền 
    void xuat();
    PhanSo cong(const PhanSo& p)//2 ngoi nên cần truyền vào 1 tham số 
    void tru(PhanSo p);
    float nhan(PhanSo p);
    PhanSo chia(PhanSo p);
    PhanSo rutgon();
    void sosanh(PhanSo p);
    bool sosanhlonhon(PhanSo p);
};
/*(const PhanSo &p) chiếu hang : tiết kiệm thời gian bộ nhớ, chạy nhanh hơn, thay doi dc gia tri
 */
int UCLN(int a, int b);
void PhanSo::nhap() {
    cout << "nhap tu:";
    cin >> tu; //cin >> this->tu;
    cout << "nhap mau";
    cin >> mau;
}
void PhanSo::xuat() {
    cout << "\t" << tu << "/" << mau << endl;
}
PhanSo PhanSo::cong(PhanSo p) {
    PhanSo t;
    t.tu = /*this->*/ tu * p.mau + mau * p.tu;
    t.mau = mau * p.mau;
    return t;
}
void PhanSo::tru(PhanSo p) {
    cout<<tu * p.mau - mau * p.tu<<"/"<<mau *p.mau
}
float PhanSo::nhan(PhanSo p) {
    float t = (float)(tu * p.tu) / (mau * p.mau);
    return t;
}
PhanSo PhanSo::chia(PhanSo p) {
    PhanSo t;
    t.tu = /*this->*/ tu * p.mau + mau * p.tu;
    t.mau = mau * p.mau;
    return t;
    void PhanSo::sosanh(PhanSo p) {
        if (float(tu) / mau < (float(p.tu) / p.mau)) {
            cout << "p1 be hon p2 " << endl;
        }
        else if ((float(tu) / mau) > (float(p.tu) / p.mau) {
            cout <<"p1 lon hon p2"<<endl;
        }
        else {
            cout<<"p1 = p2"<<endl;
        }
    }
    bool PhanSo::sosanhlonhon(PhanSo p) {
        if((float(tu)/mau)>(float(p.tu)))
    }
}int UCLN(int a, int b) {
    a = abs(a);
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}
PhanSo PhanSo::rutgon(){
    int ucln = UCLN(tu, mau);
    //PhanSo t;
    //t.tu = tu / ucln;
    //t.mau = mau / ucln;
    tu = tu / ucln;
    mau = mau / ucln;
    return *this;
    }
int main() {
    PhanSo p1, p2,p3 ;
    p1.nhap();
    cout << "p1 chua rut gon: ";
    p1.xuat();
    cout << "p2 da rut gon: ";
    (p1.rutgon()).xuat();
    p2.nhap();
    p2.xuat();
    p1.sosanh(p2);
    if (p1.sosanhlonhon(p2) == true) {
        cout << 'p1 lon hon p2";
    }
    else {
        cout << "p1 <=p2 ";
    }
    //cout << "tong la: ";
    ////p3 = p1.cong(p2);
    ////p3.xuat();
    //(p1.cong(p2)).xuat();
    //cout << "hieu la:";
    //(p1.tru(p2));
    //cout << "Tich la: "<< p1.nhan(p2);
    //cout << "thuong la: " ;
    //(p1.chia(p2)).xuat();
    cout << endl;
    system("pause");
}