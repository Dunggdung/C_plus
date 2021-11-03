// Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;
class HocSinh {
    private:
    string HoTen;
    float van;
    float toan;
    static int STT;
    public:
    friend istream& operator >> (istream& is, HocSinh& hs);
    friend ostream& operator << (ostream& os,const HocSinh& hs);
    HocSinh();
    HocSinh(string HoTen);
    HocSinh(const HocSinh &x);
    HocSinh(string HoTen,float van,float toan);
    bool operator > (HocSinh s);
    bool operator < (HocSinh s);
    bool operator <=( HocSinh s);
    bool operator >=( HocSinh s);
    bool operator ==( HocSinh s);
    bool operator !=( HocSinh s);
    void xuat ();
    float DiemTB();
    // ~HocSinh(){
    //     cout <<"Huy Doi Tuong";
    // }
};
int HocSinh::STT = 0;
float HocSinh::DiemTB(){
    float diem;
    diem = (van+toan)/2;
    return diem;
}
HocSinh::HocSinh(){
    this->HoTen = " ";
    this->van = 0;
    this->toan = 0;
}
HocSinh::HocSinh(string HoTen){
    this->HoTen = HoTen;
    this->toan = 0;
    this->van = 0;
}
HocSinh::HocSinh(const HocSinh &x){
    this->HoTen = x.HoTen;
    this->van = x.van;
    this->toan = x.toan;
}
HocSinh::HocSinh(string HoTen,float van,float toan){
    this->HoTen = HoTen;
    this->toan = toan;
    this->van = van;
}
bool HocSinh::operator<(HocSinh s){
    return this->DiemTB() < s.DiemTB();
}
bool HocSinh::operator > (HocSinh s){
    return this->DiemTB() > s.DiemTB();
}
bool HocSinh::operator <=( HocSinh s){
    return ((this->DiemTB() < s.DiemTB()) || (this->DiemTB() == s.DiemTB()));
}
bool HocSinh::operator >=( HocSinh s){
    return ((this->DiemTB() > s.DiemTB()) || (this->DiemTB() == s.DiemTB()));
}
bool HocSinh::operator ==( HocSinh s){
    return this->DiemTB() == s.DiemTB();
}
bool HocSinh::operator !=( HocSinh s){
    return this->DiemTB() != s.DiemTB();
}
istream& operator >> (istream& is, HocSinh& hs){
    // HocSinh.STT ++;
    // cout<<"STT: " << HocSinh.STT;
    fflush(stdin);
	cout <<"Nhap ho ten: ";
	getline(is, hs.HoTen);
	cout<<"nhap diem toan: ";
	is >> hs.toan;
	cout <<"Nhap diem van: ";
	is>>hs.van;
    return is;
}
ostream& operator << (ostream& os, const HocSinh& hs) {
    hs.STT ++;
    os << "ho ten: " << hs.HoTen << endl;
    os << "diem toan : " << hs.toan << endl;
    os << "diem van: " << hs.van << endl;
    return os;
}
void HocSinh::xuat(){
    cout << "STT: " <<STT <<" Ho Ten: " << HoTen << " Diem Toan : " << toan << " Diem Van: " << van << endl;
}
int main (){
    HocSinh a ("A",7.8,4.9);
    HocSinh b ("B",9.8,5.9);
	if(a>b) cout<<"Lon Hon"<<endl;
    if(a<b) cout<<"Nho Hon"<<endl;
    if(a>=b) cout<<"Lon Hon Hoac Bang"<<endl;
    if(a<=b) cout<<"Nho Hon Hoac Bang"<<endl;
    if(a==b) cout<<"Bang"<<endl;
    if(a!=b) cout<<"Khong Bang"<<endl;
    a = b;
    cout << "A = B : "<<endl;
    a.xuat();
    return 0;
}