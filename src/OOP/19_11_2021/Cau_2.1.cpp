//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;

class MyAttr{
    protected:
        int x;
    public:
        MyAttr();
        void Nhap();
        void Xuat();
};
MyAttr::MyAttr(){
    x = 0;
}
void MyAttr::Nhap(){
    cout << "Nhap So Hieu: ";
    cin >> x;
}
void MyAttr::Xuat(){
    cout <<endl<< "So Hieu: "<< x <<endl;
}
class MyDate{
    protected:
        int ngay,thang,nam;
    public:
        MyDate();
        void NhapDate();
        bool operator > (MyDate &b);
        void XuatDate();
};
MyDate::MyDate(){
    ngay = 1;
    thang = 1;
    nam = 1;
}
void MyDate::NhapDate(){
    cout <<"Date: "<<endl;
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}
void MyDate::XuatDate(){
    cout <<"Date: "<< ngay <<"-"<< thang <<"-"<< nam << endl;
}
bool MyDate::operator > (MyDate &a){
    if(nam > a.nam) 
        return true;
    else if(nam == a.nam) {
        if(thang > a.thang) 
            return true;
        else if(thang == a.thang) {
            if(ngay > a.ngay) 
                return true;
            else 
                return false;
        }
        else 
            return false;
    }
    else
        return false;
}
class Myfile : public MyDate , public MyAttr{
        string name;
        int size;
    public:
        void NhapFile();
        void XuatFile();
        void sapxep ();
};
void Myfile::NhapFile(){
    MyAttr::Nhap();
    MyDate::NhapDate();
    cout <<"Nhap Ten File: ";
    cin >> name;
    cout <<"Nhap Size: ";
    cin >> size;
}
void Myfile::XuatFile(){
    MyAttr::Xuat();
    MyDate::XuatDate();
    cout <<"Ten File: "<< name <<endl;
    cout <<"Size: "<< size <<endl;
}
void Myfile::sapxep(){
    Myfile *a;
    for(int i=0; i < 3; i++){
        for(int j=i+1; j < 4; j++){
            if ((a+i)->MyDate > (a+j)->MyDate){
                swap((a+i),(a+j));
            }
        }
    }
    XuatFile();
}
int main(){
    Myfile *a= new Myfile[4];
    for(int i = 0; i < 4; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        cout <<"----------------------"<<endl;
        (a+i)->NhapFile();
    }
    for(int i = 0; i < 4; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        (a+i)->XuatFile();
        cout <<"----------------------"<<endl;
    }
    a->sapxep();
    delete [] a;
    return 0;
}