//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;
class MyDate{
    private:
        int ngay,thang,nam;
    public:
        MyDate();
        ~MyDate();
        void input();
        void output();
        friend bool operator >(MyDate &a, MyDate &b);
};
MyDate::MyDate(){
    this->ngay =0;
    this->thang =0;
    this->nam =0;
}
MyDate::~MyDate(){}
void MyDate::input(){
    cout<<"\nNhap ngay: "; cin>>ngay;
    cout<<"\nNhap thang: "; cin>>thang;
    cout<<"\nNhap nam: "; cin>>nam;
}
void MyDate::output(){
    cout<<endl<<ngay<<"-"<<thang<<"-"<<nam;
}
bool operator >(MyDate &a, MyDate &b){
    if(a.nam > b.nam) return true;
    else if(a.nam == b.nam) {
        if(a.thang > b.thang) return true;
        else if(a.thang == b.thang) {
            if(a.ngay > b.ngay) return true;
        }
    }
    return false;
}
void inputs (MyDate a[], int n){
    for(int i=0; i<n; i++){
        a[i].input();
    }
}
void outputs (MyDate a[], int n){
    for(int i=0; i<n; i++){
        a[i].output();
    }
}
void sapxep (MyDate a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j])
            swap(a[i], a[j]);
        }
    }
}
int main(){
    int n;
    cout<<"Nhap so luong: ";
    cin>>n;
    MyDate a[n];
    inputs(a,n);
    outputs(a,n);
    
    sapxep(a,n);
    cout<<endl<<"Sau khi sap xep la: ";
    outputs(a,n);
    return 0;
}