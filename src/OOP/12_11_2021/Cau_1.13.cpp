//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;
class Student {
    private:
        string hoten;
        float diem1,diem2;
        float diemtb;
    public:
        float diemTB(){
            diemtb = (diem1+diem2*2)/3;
            return (float)diemtb;
        }
        Student ();
        void Nhap ();
        void Xuat();
        bool operator > (Student a);
};
Student::Student (){
    hoten = "";
    diem1 = 0;
    diem2 = 0;
}
void Student::Nhap (){
    fflush(stdin);
    cout <<"Nhap Ho Ten: ";
    getline(cin,hoten);
    cout <<"Nhap Diem Ky 1: ";
    cin >> diem1;
    cout <<"Nhap Diem Ky 2: ";
    cin >> diem2;
}
void Student::Xuat(){
    cout <<"Ten: "<<hoten<<" || Diem Ky 1: "<<diem1<<" || Diem Ky 2: "<<diem2<<" || Diem Trung Binh: "<<diemTB()<<endl;
}
bool Student:: operator > (Student a){
    return diemTB()>a.diemTB();
}
void input(Student a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"Nhap Sinh Vien " << i+1 << endl ;
        a[i].Nhap() ;
    } 
}
// xuất nhìu phân số
void output(Student a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"Sinh Vien " << i+1 << ": " ;
        a[i].Xuat();
    }
}
void sosanh (Student a,Student b){
    if (a > b){
        cout <<"Diem trung binh sinh vien 1 lon hơn sinh vien 2!"<<endl;
    }else {
        cout <<"Diem trung binh sinh vien 1 nho hon hoac bang sinh vien 2!"<<endl;
    }
}
void sapxep(Student a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (a[j] > a[i]){
                swap(a[i], a[j]);
            }
        }
    }
}
int main (){
    Student sv1;
    Student sv2;
    cout <<"Sinh Vien 1~"<<endl;
    sv1.Nhap(); 
    cout <<"Sinh Vien 2~"<<endl;
    sv2.Nhap();
    sv1.Xuat();
    sv2.Xuat();
    sosanh (sv1, sv2);

    Student s[5];
    input(s,5);
    output(s,5);
    cout <<endl<<"Danh sach sinh vien sap xep theo diem trung binh ca nam giam dan!"<<endl;
    sapxep(s,5);
    output(s,5);
    return 0;
}