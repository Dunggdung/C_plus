/*
Phạm Nguyễn Thùy Dung
6151071003

Cho lớp TaiKhoan:
class TaiKhoan  {
  private:
         float  m_fSoDu = 0;
  public:
      float baoSoDu() {   
            return m_fSoDu; 
      }
void napTien(float fSoTien) {   
       m_fSoDu += fSoTien;  
}
void rutTien(float fSoTien)  {
   if (fSoTien <= m_fSoDu)
          m_fSoDu -= fSoTien;
  }  
};
 Dựa trên lớp TaiKhoan, xây dựng lớp TaiKhoanTietKiem như sau: 
  - Có thêm thông tin: 
•Kỳ hạn gửi.
•Lãi suất.
•Số tháng đã gửi.
  - Khi nạp tiền, số tháng đã gửi được tính lại từ đầu.
  - Chỉ được rút tiền khi đến kỳ hạn.
  - Cho phép tăng số tháng đã gửi.
  - Tính số dư tại thời điểm hiện tại.
  */
 #include <iostream>
 using namespace std;
 class TaiKhoan  {
  private:
         float  m_fSoDu = 0;
  public:
    float baoSoDu() {   
            return m_fSoDu; 
    }
    void napTien(float fSoTien) {   
       m_fSoDu += fSoTien;  
    }
    void rutTien(float fSoTien)  {
        if (fSoTien <= m_fSoDu)
            m_fSoDu -= fSoTien;
    }  
};

class TaiKhoanTietKiem : protected TaiKhoan {
    private:
        int kyhan;
        float lai;
        int thang;
    public:
        void nhap();
        void xuat();
        void nap(float &sotien);
        void ruttien(float &sotien);
        void tangthang();
        void sodu();
};
void TaiKhoanTietKiem::nhap(){
    cout <<"Ky Han Gui: ";
    cin >> kyhan;
    cout <<"So Thang Da Gui: ";
    cin >> thang;
    cout <<"Lai Suat: ";
    cin >> lai;
}
void TaiKhoanTietKiem::xuat(){
    cout << "************************"<<endl;
    cout << "Han Gui: "<<kyhan<<endl;
    cout << "Lai: "<<lai<<" %"<<endl;
    cout << "So Thang: "<<thang<<endl;
}
void TaiKhoanTietKiem::nap(float &sotien){
    cout <<"Nhap so tien can nap: ";
    cin >> sotien;
    napTien(sotien);
    thang = 0;
    cout <<"So tien: "<< baoSoDu() <<endl;
    cout <<"Thang: "<<thang<<endl;
}
void TaiKhoanTietKiem::ruttien(float &sotien){
    if(thang<kyhan){
        cout<<"Chua den han"<<endl;
        return;
    }else{
        float soTien;
        cout<<"Nhap so tien can rut: ";
        cin>>soTien;
        if(soTien <= baoSoDu()){
            rutTien(soTien);
            cout<<"Da rut "<<soTien<<endl;
        }else{
            cout<<"Khong du so du"<<endl;
        }
    }
}
void TaiKhoanTietKiem::tangthang(){
    cout<<"Ky han gui: ";
    cin>>kyhan;
    thang += kyhan;
    cout<<"Thang: "<<thang<<endl;
}
void TaiKhoanTietKiem::sodu(){
    cout<<"So Du Hien Tai: "<<baoSoDu() <<endl;
}
int main(){
    float tiennap,tienrut;
    TaiKhoanTietKiem a;
    a.nhap();
    a.xuat();
    a.nap(tiennap);
    a.tangthang();
    a.ruttien(tienrut);
    a.sodu();
    return 0;
}