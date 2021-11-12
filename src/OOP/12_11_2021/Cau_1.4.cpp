//Phạm Nguyễn Thùy Dung 6151071003
#include<iostream>
using namespace std;
class vector{
    private:
        int n;
        float *v;
    public:
        vector(int size);
        vector(vector &a);
        ~vector();
        void Nhap();
        void Xuat();
        bool check(vector &b);
        friend vector operator +(vector &a,vector &b);
        void operator =(vector &a);
};
vector::vector(int size){
    n = size;
    v = new float[n];
}
vector::vector(vector &a){
    n = a.n;
    v = new float [n];
    for (int i=0; i<n; i++){
       v[i]=a.v[i];
    }
}
vector::~vector(){
    delete v;
}
void vector::Nhap(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i<<"]: ";
        cin>>v[i];
    }
}
bool vector::check(vector &b){
    return n==b.n;
}
vector operator +(vector &a,vector &b){
    vector c = a;
    for (int i=0; i<a.n; i++){
        c.v[i]=a.v[i]+b.v[i];
    }
    return c;
}
void vector:: operator =(vector &a){
    n = a.n;
    v = new float[n];
    for (int i=0; i<n; i++){
        v[i]=a.v[i];
    }
}
void vector::Xuat(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i+1<<"] = "<<v[i];
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Nhap so luong phan tu vector A: "; cin>>n;
    vector a(n);
    a.Nhap();
    cout <<"Vector A: "<<endl;
    a.Xuat();
    cout<<"Nhap so luong phan tu vector B: "; cin>>n;
    vector b(n);
    b.Nhap();
    cout <<"Vector B: "<<endl;
    b.Xuat();
    cout<<"Tong 2 vector A,B: "<<endl;
    if(a.check(b)){
        (a+b).Xuat();
    }else   cout<<"Khong the thuc hien phep toan!"<<endl;
}