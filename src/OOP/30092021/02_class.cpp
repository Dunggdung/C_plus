/* Phạm Nguyễn Thùy Dung
MSSV: 6151071003
Thông tin một học sinh bao gồm:
    + Họ tên 
    + Điểm văn, toán
Xây dựng lớp học sinh cho phép thực hiện các thao tác:
    + Nhập xuất
    + Lấy họ tên điểm văn , toán
    + Gán giá trị cho họ tên , điểm văn , toán 
    + Tính điểm trung bình
    + Xếp loại theo tiêu chí:
        - Giỏi (>= 8.0)
        - Khá (>= 7.0)
        - Trung bình (>= 5.0)
        - Yếu (< 5)
*/
#include <iostream>
using namespace std;

class HocSinh {
private:
    string ten;
    float van;
    float toan;
public:
    void nhap();    // nhập thông tin học sinh
    void xuat();    // xuất thông tin học sinh
    string getTen(); //lấy Họ và tên
    float getVan(); //lấy điểm văn
    float getToan (); //lấy điểm toán
    float trungbinh(); //tính điểm trung bình 
    void setTen (string ten);
    void setToan (float toan);
    void setVan (float van);
};
void xeploai (float a); // xếp loại học lực


void HocSinh::nhap(){
    fflush(stdin);
    cout <<"*** Nhap Ho Va Ten Hoc Sinh: ";
    getline (cin,ten);
    do {
        cout <<"*** Nhap Diem Van: ";
        cin >> van;
        if (van < 0 ){
            cout <<endl<< "*** Xin Vui Long Nhap Lai!"<<endl;
            cout <<"*** Nhap Diem Van: ";
            cin >> van;
        }
    } while (van < 0);
    do {
        cout <<"*** Nhap Diem Toan: ";
        cin >> toan;
        if (toan < 0 ){
            cout <<endl<< "*** Xin Vui Long Nhap Lai!"<<endl;
            cout <<"*** Nhap Diem Toan: ";
            cin >> toan;
        }
    } while (toan < 0);
}
void HocSinh::xuat(){
    cout <<"Ho va Ten: "<<ten <<" |Diem Van: "<< van<< " |Diem Toan: "<<toan<<endl;
}
string HocSinh::getTen(){
    return ten;
}
float HocSinh::getVan(){
    return van;
}
float HocSinh::getToan(){
    return toan;
}
float HocSinh::trungbinh(){
    float tb;
    tb = (van+toan)/2;
    return tb;
}
void xeploai (float a){
    // Xếp loại theo tiêu chí:
    //     - Giỏi (>= 8.0)
    //     - Khá (>= 7.0)
    //     - Trung bình (>= 5.0)
    //     - Yếu (< 5)
    if (a >= 8.0){
        cout <<"Gioi" << endl;
    }
    else if (a >=7.0 && a < 8.0){
        cout <<"Kha"<< endl;
    }
    else if (a >= 5.0 && a < 7.0){
        cout <<"Trung Binh"<< endl;
    }
    else {
        cout <<"Yeu"<< endl;
    }
}
void HocSinh:: setTen(string ten){
    this->ten = ten;
}
void HocSinh:: setToan(float toan){
    this->toan = toan;
}
void HocSinh:: setVan(float van){
    this->van = van;
}
int main (){
    HocSinh hs;
    string ten; // do hàm set
    float toan,van; // khai báo (hàm set)

    hs.nhap ();
    hs.xuat();

    cout <<"Diem Trung Binh: "<<hs.trungbinh()<<endl;

    cout << "Xep Loai Hoc Sinh: ";
    xeploai(hs.trungbinh());

    return 0;
}