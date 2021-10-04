/* Phạm Nguyễn Thùy Dung
MSSV: 6151071003
Xây dựng class đơn thức
+ Thuộc tính : Bậc, hệ số
+ Phương thức:
    + Nhập, Xuất, giá trị tại x, so sánh
    + Tính đạo hàm, nguyên hàm
    + Lấy hệ số, số mũ
    + Cộng , trừ ( đơn thức cùng bậc)
    + Nhân , chia (đơn thức khác bậc)*/
#include <iostream>
#include <math.h>
using namespace std;
class Donthuc {
private:
    float bac; 
    float heso;
public:
    void Nhap();    // Nhập
    void Xuat();    //xuất
    float getHeso(); // lấy hệ số
    float getMu(); // lấy mũ số
    float giaTrix(float x); // giá trị đơn thức tại x
    void sosanh (Donthuc a);    //so sánh 2 đơn thức
    Donthuc cong(Donthuc a);    // cộng 2 đơn thức
    Donthuc tru(Donthuc a);     // trừ 2 đơn thức
    Donthuc nhan(Donthuc a);    // nhân 2 đơn thức
    Donthuc chia(Donthuc a);    // chia 2 đơn thức
    Donthuc daoham();   // Đạo hàm đơn thức
    Donthuc nguyenham(); // Nguyên hàm đon thuc
};
void Donthuc::Nhap(){
    cout << "***Nhap he so: ";
    cin >> heso;
    cout <<"***Nhap bac don thuc: ";
    cin >> bac;
}
void Donthuc::Xuat(){
    cout<< "***Don thuc: "<<heso <<"x^"<<bac<<endl;
}
float Donthuc::getHeso(){
    return heso;
}
float Donthuc::getMu(){
    return bac;
}
float Donthuc:: giaTrix(float x){
    float giatri = 0;
        giatri = heso*pow(x,bac);
    return giatri;
}
void Donthuc::sosanh (Donthuc a){
    if (heso*pow(2,bac) > a.heso*pow(2,a.bac)){
        cout << "Don thuc 1 lon hon don thuc 2 "<< endl;
    }
    else if (heso*pow(2,bac) < a.heso*pow(2,a.bac)){
        cout << "Don thuc 1 be hon don thuc 2 "<< endl;
    }
    else {
        cout << "Don thuc 1 bang don thuc 2"<<endl;
    }
}
Donthuc Donthuc::cong(Donthuc a){
    Donthuc total;
    total.heso = heso + a.heso;
    total.bac = bac;
    return total;
}
Donthuc Donthuc::tru(Donthuc a){
    Donthuc hieu;
    hieu.heso = heso - a.heso;
    hieu.bac = bac;
    return hieu;
}
Donthuc Donthuc::nhan(Donthuc a){
    Donthuc temp;
    temp.heso = heso * a.heso;
    temp.bac = bac + a.bac;
    return temp;
}
Donthuc Donthuc::chia(Donthuc a){
    Donthuc temp;
    temp.heso = heso / a.heso;
    temp.bac = bac - a.bac;
    return temp;
}
Donthuc Donthuc::daoham(){
    Donthuc temp;
       if(bac > 1){
        temp.heso = heso*bac;
        temp.bac = --bac;
    }
    else if (bac = 1){
        temp.heso = heso;
        temp.bac = --bac;
    }
    else  {
        temp.heso = heso = 0;
        temp.bac = bac = 0;
    }
    return temp;
}
Donthuc Donthuc::nguyenham(){
    Donthuc temp;
    temp.bac = ++bac;
    temp.heso = float(heso / bac);
    return temp;
}
int main () {
    Donthuc dt1,dt2;
    float x;
    dt1.Nhap();
    dt1.Xuat();

    cout<<"Don Thuc dao ham! "<< endl;
    dt1.daoham().Xuat();

    cout<<"Don Thuc Nguyen ham! "<< endl;
    dt1.nguyenham().Xuat();

    cout << "Nhap gia tri x: ";
    cin >> x;
    cout<< "Gia tri don thuc khi x = "<<x<<" la: "<<dt1.giaTrix(x)<<endl;

    dt2.Nhap();
    dt2.Xuat();
    dt1.Xuat();
    dt1.sosanh(dt2);

    cout << "Tong hai don thuc " << endl;
    dt1.cong(dt2).Xuat();

    cout << "Hieu hai don thuc " << endl;
    dt1.tru(dt2).Xuat();

    cout << "Tich hai don thuc " << endl;
    dt1.nhan(dt2).Xuat();

    cout << "Thuong hai don thuc " << endl;
    dt1.chia(dt2).Xuat();
    
    return 0;
}
