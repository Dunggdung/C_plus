// Phạm Nguyễn Thùy Dung 6151071003
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
        void operator =(vector &a);
        friend vector operator *(float k,vector &a);
};
// thiết lập bộ nhớ
vector::vector(int size){
    n = size;
    v = new float[n];
}
// sao chép
vector::vector(vector &a){
    n = a.n;
    v = new float [n];
    for (int i=0; i<n; i++){
       v[i]=a.v[i];
    }
}
// hàm hủy
vector::~vector(){
    delete v;
}
void vector::Nhap(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i+1<<"]: ";
        cin>>v[i];
    }
}
void vector:: operator =(vector &a){
    n = a.n;
    v = new float[n];
    for (int i=0; i<n; i++){
        v[i]=a.v[i];
    }
}
vector operator *(float k,vector &a){
    vector c = a;
    for (int i=0; i<a.n; i++){
        c.v[i]=k*a.v[i];
    }
    return c;
}
void vector::Xuat(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i+1<<"] = "<<v[i];
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Nhap so luong phan tu vector: ";
    cin>>n;
    vector a(n);
    // nhap vector
    a.Nhap();
    // xuat vector
    cout <<"Cac Vector da nhap~~~"<<endl;
    a.Xuat();
    // nhap so thuc k
    float k;
    cout<<"Nhap so thuc k: ";
    cin>>k;
    // xuat du lieu k*a
    (k*a).Xuat();
}