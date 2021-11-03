/* Phạm Nguyễn Thùy Dung
    6151071003
- xây dựng lớp cơ sở GiangVien
    - thuộc tính: MaSo, HoTen, Tuoi, Luong
    - phương thức: Nhap,Xuat,TinhLuong,getLuong
-xây dựng lớp dẫn xuất GiangVienCoHuu kế thừa lớp GiangVien
    -thuộc tính : HeSoLuong, ThamNien
    -phương thức: Nhap,Xuat,TinhLuong(HeSoLuong*1600 + ThamNien*500)
-xây dựng lớp dẫn xuất GiangVienThinhGiang kế thừa lớp GiangVien
    -thuộc tính : SoTiet, DonGia
    -phương thức: Nhap,Xuat,TinhLuong(SoTiet*DonGia)
-Xây dựng QuanLyGiangVien
    -thuộc tính: DanhSachGiangVien (dùng cấu trúc dữ liệu vector để lưu trữ)
    -phương thức: Nhap,Xuat,SapXepLuongTangDan, LuongLonNhat,TongLuongGiangVien.
*/
#include <iostream>
using namespace std;

class GiangVien{
    private:
        string MaSo, HoTen;
        int Tuoi;
        float Luong;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual float TinhLuong() = 0;// Hàm thuần ảo
        float getLuong ();
};
class GiangVienCoHuu :public GiangVien{
    private:
        float HeSoLuong;
        int ThamNien;
    public:
        void Nhap(GiangVienCoHuu &a);
        void Xuat();
        float TinhLuong();
};
class GiangVienThinhGiang :public GiangVien{
    private:
        int SoTiet, DonGia;
    public:
        void Nhap();
        void Xuat();
        float TinhLuong();
};
// class GiangVienThinhGiang :public GiangVien{
//     private:
//         GiangVien DanhSachGiangVien;
//     public:
//         void Nhap();
//         void Xuat();
//         void SapXepLuongTangDan();
//         void LuongLonNhat();
//         float TongLuongGiangVien();
// };

void GiangVien:: Nhap(){
    fflush(stdin);
    cout <<"Nhap Ma So Giang Vien: ";
    getline(cin,MaSo);
    cout <<"Nhap Ho Ten Giang Vien: ";
    getline(cin,HoTen);
    cout <<"Nhap Tuoi Giang Vien: ";
    cin >> Tuoi;
    cout <<"Nhap Luong Giang Vien: ";
    cin >> Luong;
}
void GiangVien:: Xuat(){
    cout <<endl<<"MS: "<<MaSo<<" ||Ho Ten: "<<HoTen<<" ||Tuoi: "<<Tuoi;//" ||Luong: ",Luong<<endl;
}
int GiangVien:: getLuong (){
    return Luong;
}
void GiangVienCoHuu:: Nhap(GiangVienCoHuu &a){
    GiangVien * b = static_cast<b *>(&a);
    b.Nhap();
    cout <<"Nhap He So Luong Giang Vien: ";
    cin >> HeSoLuong;
    cout <<"Nhap Tham Nien Giang Vien: ";
    cin >> ThamNien;
}
float GiangVienCoHuu:: TinhLuong(){
    Luong = HeSoLuong*1600 + ThamNien*500;
    return Luong;
}
void GiangVienCoHuu:: Xuat(){
    GiangVien:: Xuat();
    cout <<" ||Luong: "<<Luong <<endl;
}
float GiangVienThinhGiang:: TinhLuong(){
    Luong = SoTiet*DonGia;
    return Luong;
}
void GiangVienThinhGiang:: Nhap(GiangVienThinhGiang &a){
    GiangVien * b = static_cast<b *>(&a);
    b.Nhap();
    cout <<"Nhap So Tiet Giang Vien: ";
    cin >> SoTiet;
    cout <<"Nhap Don Gia Giang Vien: ";
    cin >> DonGia;
}
void GiangVienThinhGiang:: Xuat(){
    GiangVien:: Xuat();
    cout <<" ||Luong: "<<Luong <<endl;
}
int main (){
    GiangVienCoHuu a;
    a.Nhap();
    a.Xuat();

    return 0;
}