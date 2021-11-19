//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;

class SV{
    protected: 
        string Lop;
        string HoTen;
    public:
        SV();
        ~SV(){}
        void Enter();
        void Print();
};
SV::SV(){
    HoTen = " ";
    Lop = " ";
}
void SV::Enter(){
    fflush(stdin);
    cout << "Ho Ten: ";
    getline(cin,HoTen);
    cout << "Lop: ";
    cin >> Lop;
}
void SV:: Print(){
    cout << "Ho Ten: "<<HoTen<<endl;
    cout << "Lop: "<<Lop<<endl;
}
class SVSP : public SV{
    protected: 
        float dtb;
        float hocbong;
    public:
        SVSP();
        void Enter();
        void Print();
};
SVSP::SVSP(){
    dtb = 0;
    hocbong = 0;
}
void SVSP::Enter(){
    SV::Enter();
    fflush(stdin);
    cout << "Nhap Diem TB: ";
    cin >> dtb;
    cout << "Nhap Hoc Bong: ";
    cin >> hocbong;
}
void SVSP::Print(){
    SV::Print();
    cout << "Diem TB: "<<dtb<<endl;
    cout << "Hoc Bong: "<<hocbong<<endl;
}
class SVCN : public SVSP{
    protected:
        float hocphi;
    public:
        SVCN();
        void Enter();
        void Print();
};
SVCN::SVCN(){
    hocphi = 0;
}
void SVCN::Enter(){
    SVSP::Enter();
    cout <<"Nhap Hoc Phi: ";
    cin >> hocphi;
}
void SVCN::Print(){
    SVSP ::Print();
    cout << "Hoc Phi: "<<hocphi<<endl;
}
int main(){
    SVCN *a = new SVCN[3];
    for (int i = 0; i < 3; i++){
        (a+i)->Enter();
    }
    cout <<endl;
    for (int i = 0; i < 3; i++){
        (a+i)->Print();
    }
    return 0;
}