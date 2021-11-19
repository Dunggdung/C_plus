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
class SVTC : public SV{
    protected: 
        float hocphi;
    public:
        SVTC();
        void Enter();
        void Print();
};
SVTC::SVTC(){
    hocphi = 0;
}
void SVTC::Enter(){
    SV::Enter();
    fflush(stdin);
    cout << "Nhap Hoc Phi: ";
    cin >> hocphi;
}
void SVTC::Print(){
    SV::Print();
    cout << "Hoc Phi: "<<hocphi<<endl;
}
class SVCN : public SVTC{
    protected:
        float Dtb;
        float hocbong;
    public:
        SVCN();
        void Enter();
        void Print();
        bool operator > (SVCN &a);
};
SVCN::SVCN(){
    Dtb = 0;
    hocbong = 0;
}
void SVCN::Enter(){
    SVTC::Enter();
    cout <<"Nhap Diem TB: ";
    cin >> Dtb;
    cout <<"Nhap Hoc Bong: ";
    cin >> hocbong;
}
void SVCN::Print(){
    SVTC ::Print();
    cout << "Diem TB: "<<Dtb<<endl;
    cout << "Hoc Bong: "<<hocbong<<endl;
}
bool SVCN::operator > (SVCN &a){
    if (Dtb > a.Dtb)
    return true;
}
void SVCN::sapxep(){
    SVCN *a;
    for(int i=0; i < 3; i++){
        for(int j=i+1; j < 4; j++){
            if ((a+i) > (a+j)){
                swap((a+i),(a+j));
            }
        }
    }
    Print();
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
    a->sapxep();
    return 0;
}