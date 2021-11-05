
#include<iostream>
using namespace std;
class MH{
    private:
        string tmh;
        int sl;
        float dg;
    public:
        void Nhap();
        void In();
        float tien();
        int getSL(){
            return sl;
        }
        float getDG(){
            return dg;
        }
};
class HD:public MH{
    private:
        string thd; 
        MH *dsmh;
        int slmh;
    public:
        float tongt();
        void Nhap();
        void In();
        string getTHD(){
            return thd;
        }
};
void MH::Nhap(){
    fflush(stdin);
    cout <<"Nhap ten mat hang: ";
    getline(cin,tmh);
    cout <<"Nhap so luong: ";
    cin >>sl;
    cout <<"Nhap don gia: ";
    cin >>dg;
}
void MH::In(){
    cout <<"Ten mat hang: "<<tmh<<endl;
    cout<<"So luong: "<<sl<<endl;
    cout<<"Don gia: "<<dg<<endl;
}
void HD::Nhap(){
    fflush(stdin);
    cout <<"Nhap ten hoa don: ";
    getline(cin,thd);
    cout <<"Nhap so luong mat hang: ";
    cin >>slmh;
    cout<<endl<<"Danh sach mat hang: "<<endl;
    fflush(stdin);
    dsmh = new MH[slmh];
    for(int i=0;i<slmh;i++){
        cout<<"***Mat hang thu: "<<i<<endl;
        dsmh[i].Nhap();
    }
}
void HD::In(){
    cout <<"Hoa Don: "<<thd<<endl;
    cout<<"So luong: "<<slmh<<endl;
    cout <<"Danh sach mat hang"<<endl;
    for(int i=0;i<slmh;i++){
        cout<<endl<<"***Mat hang thu: "<<i<<endl;
        dsmh[i].In();
    }
    cout <<"Tong tien: "<<tongt()<<endl;
}
float MH::tien(){
    float t;
    t = sl * dg;
    return t;
}
float HD::tongt(){
    int s = 0;
    for(int i=0;i<slmh;i++)
        s += dsmh[i].tien();
    return s;
}
void MaxTien(HD *k, int n){
    int dem = 0;
    float max = k[0].tongt();
    for(int i=0;i<n;i++){
        if(max < k[i].tongt()){
            max = k[i].tongt();
        }
    }
    for(int i=0;i<n;i++){
        if(k[i].tongt()==max){
            k[i].In();
            break;
        }
    }
}
void MinTien(HD *k, int n){
    int dem = 0;
    float min = k[0].tongt();
    for(int i=0;i<n;i++){
        if(min > k[i].tongt()){
            min = k[i].tongt();
        }
    }
    for(int i=0;i<n;i++){
        if(k[i].tongt()==min){
            k[i].In();
            break;
        }
    }
}
void timkiem(HD *k, int n){
    string ten;
    fflush(stdin);
    cout <<"Nhap ten can tim: ";
    getline(cin,ten);
    for(int i=0;i<n;i++){
        if(k[i].getTHD()==ten){
            k[i].In();
            break;
        }
        else{
            cout <<"Khong tim thay ten !!!"<<endl;
            break;
        }
    }
}
int main(){
    HD *a;
    int n;
    cout <<"Nhap so luong hoa don: ";
    cin >> n;
    a = new HD[n];
    for (int i = 0; i < n; i++ ){
        cout <<endl<< "Hoa don "<<i+1<<endl;
        a[i].Nhap();
    }
    cout<<endl<<"Xuat hoa don"<<endl;
    for (int i = 0; i < n; i++ ){
        cout <<endl<< "Hoa don "<<i+1<<endl;
        a[i].In();
    }
    MaxTien(a,n);
    MinTien(a,n);
    timkiem(a,n);
    delete [] a;
    return 0;
}
