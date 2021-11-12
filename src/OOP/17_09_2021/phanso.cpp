// Phân số phan so
/* Phạm Nguyễn Thùy Dung
 MSSV: 6151071003
 cộng trừ nhân chia
*/
#include <iostream>
using namespace std;
class Phanso {
    private: 
        int tu,mau;
    public:
        void Nhap();
        void Xuat();
        int getTu (){
            return tu;
        }
        int getMau (){
            return mau;
        }
};
void Phanso::Nhap(){
    cout << "Nhap Tu: ";
    cin >> tu;
    do
    { //mau > 0
        cout << "Nhap Mau: ";
        cin >> mau;
        if (mau == 0)
        {
            cout<<"Vui long nhap lai!";
        }
    } while (mau == 0);
}
void Phanso::Xuat(){
    cout << "Phan so: "<< tu<<"/"<<mau<< endl;
}
int UCLN(int a, int b)
{   // tìm UCLN
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
void rutGon(int &a, int &b)
{   //rut gon phan so
    int c = UCLN(a,b);
    a = a / c;
    b = b / c;
}
void Tong(Phanso ps1, Phanso ps2)
{
    //Tong 2 phan so
    int tu1,mau1;
    tu1 = (ps1.getTu() * ps2.getMau()) + (ps1.getMau() * ps2.getTu());
    mau1 = (ps1.getMau() * ps2.getMau());
    rutGon(tu1,mau1);
    cout <<"Tong 2 Phan So: " << tu1 <<"/"<<mau1 <<endl;
}
void Hieu (Phanso ps1, Phanso ps2)
{
    //Hieu 2 phan so
    int tu1,mau1;
    tu1 = (ps1.getTu() * ps2.getMau()) - (ps1.getMau() * ps2.getTu());
    mau1 = (ps1.getMau() * ps2.getMau());
    rutGon(tu1,mau1);
    cout <<"Hieu 2 Phan So: " << tu1 <<"/"<<mau1 <<endl;
}
void Tich(Phanso ps1, Phanso ps2)
{
    //Tich 2 phan so
    int tu1,mau1;
    tu1 = ps1.getTu() * ps2.getTu();
    mau1 = ps1.getMau() * ps2.getMau();
    rutGon(tu1,mau1);
    cout <<"Tich 2 Phan So: " << tu1 <<"/"<<mau1 <<endl;
}
void Thuong(Phanso ps1, Phanso ps2)
{
    //Thuong 2 phan so
    int tu1,mau1;
    tu1 = ps1.getTu() * ps2.getMau();
    mau1 = ps1.getMau() * ps2.getTu();
    rutGon(tu1,mau1);
    cout <<"Thuong 2 Phan So: " << tu1 <<"/"<<mau1 <<endl;
}
int main (){
    Phanso ps1,ps2;
    cout<<"Nhap phan so 1 "<<endl;
    ps1.Nhap();
    cout<<"Nhap phan so 2 "<<endl;
    ps2.Nhap();
    ps1.Xuat();
    Tong (ps1,ps2);
    Hieu (ps1,ps2);
    Tich (ps1,ps2);
    Thuong (ps1,ps2);
}