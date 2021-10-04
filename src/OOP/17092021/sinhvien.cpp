// sinh vien
//Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
#include <iostream>
using namespace std;
class Sinhvien {
    private: 
        string ten;
        char gioitinh[5];
        int ngay,thang,nam;
        float diem;
    public:
        void Nhap();
        void Xuat();
};
void Sinhvien::Nhap(){
    cout << "Nhap Ho Va Ten: ";
    getline(cin, ten);
    cout << "Nhap Gioi Tinh: ";
    cin >> gioitinh;
    cout << "Nhap Ngay Sinh: "<<endl;
    cin >> ngay>>thang>>nam;
    cout << "Nhap Diem Trung Binh: ";
    cin >> diem;
}
void Sinhvien::Xuat(){
    cout << "Ten: "<< ten <<" |Gioi tinh: " << gioitinh <<" |Ngay Sinh: "<< ngay <<"/"<<thang<<"/"<<nam << "|Diem Trung Binh: " << diem;
}
int main (){
    Sinhvien sv;
    sv.Nhap();
    sv.Xuat();
}