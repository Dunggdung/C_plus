// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003

#include <iostream>
using namespace std;

class MyDate {
    protected:
        int ngay ,thang,nam;
    public:
        MyDate ();
        MyDate (int ngay, int thang, int nam);
        bool operator > (MyDate &a);
        void NhapDate ();
        void XuatDate ();
};
MyDate ::MyDate(){
    ngay = 1;
    thang = 1;
    nam = 1;
}
MyDate ::MyDate (int ngay, int thang, int nam){
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
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
void MyDate::NhapDate(){
    cout <<"*****Date: "<<endl;
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}
void MyDate::XuatDate(){
    cout <<" || Date: "<< ngay <<"-"<< thang <<"-"<< nam <<endl;
}
class Person : public MyDate{
    protected:
        string name,address;
        int phone;
    public: 
        Person(){
            name = " ";
            address = " ";
            phone = 0;
        }
        void Nhap();
        void Xuat();
};

void Person::Nhap(){
    fflush(stdin); 
    cout << "Name: ";
    getline(cin,name);
    cout << "Address: ";
    cin >> address;
    cout << "Phone: ";
    cin >> phone;
    MyDate::NhapDate();
}

void Person::Xuat(){
    cout << "Name: "<< name <<"|| Address: "<< address << "|| Phone: "<< phone;
    MyDate::XuatDate();
}
class Officer : public Person{
        float salary;
    public:
        Officer();
        void NhapCB();
        void XuatCB();
        void sapxep();
};
Officer::Officer(){
    salary = 0;
}
void Officer::NhapCB(){
    Person::Nhap();
    fflush(stdin); 
    cout << "Salary: ";
    cin >> salary;
}

void Officer::XuatCB(){
    Person::Xuat();
    cout << "Salary: "<< salary <<endl;
}
void Officer::sapxep(){
    Officer *a;
    for(int i=0; i < 3; i++){
        for(int j=i+1; j < 4; j++){
            if ((a+i)->MyDate > (a+j)->MyDate){
                swap((a+i),(a+j));
            }
        }
    }
    XuatCB();
}
int main(){
    Officer *a= new Officer[4];;
    for ( int i = 0; i < 4; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        cout <<"------------------------"<<endl; 
        (a+i)->NhapCB();
    }
    cout <<endl;
    for ( int i = 0; i < 4; i++){

        (a+i)->XuatCB();
        cout <<"------------------------"<<endl; 
    }
    a->sapxep();
    delete [] a; 
    return 0;
}