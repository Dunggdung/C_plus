//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;
class PhanSo{
    private:
        float tu;
        float mau;
    public:
        PhanSo();
        ~PhanSo();
        friend istream& operator>>(istream& is, PhanSo& phanso);
        friend float UCLN(float a, float b);
        friend void rutgon(PhanSo &phanso);
        friend ostream& operator<<(ostream& os, PhanSo phanso);
};
PhanSo::PhanSo(){
    tu = 0;
    mau = 1;
}
PhanSo::~PhanSo(){}
istream& operator>>(istream& is, PhanSo& phanso){
    cout<<"Nhap tu: ";
    is>>phanso.tu;
    do{
    cout<<"Nhap mau: ";
    is>>phanso.mau;
    }while(phanso.mau == 0);
    return is;
}
ostream& operator<<(ostream& os, PhanSo phanso){
    os<<phanso.tu<< "/" <<phanso.mau<<endl;
    return os;
}
void input(PhanSo a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Nhap phan so "<<i+1<<": "<<endl;
        cin>>a[i];
    }
}
float UCLN(float a, float b)
{

    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
void rutgon(PhanSo &phanso)
{
    int c = UCLN(phanso.tu, phanso.mau);
    phanso.tu = phanso.tu / c;
    phanso.mau = phanso.mau / c;
}
void output(PhanSo a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Phan So "<<i+1<<": ";
        rutgon(a[i]);
        cout<<a[i];
    }
}
int main(){
    int n;
    cout<<"Nhap so luong phan so: ";  cin>>n;
    PhanSo ps[n];
    input(ps,n);
    output(ps, n);
}