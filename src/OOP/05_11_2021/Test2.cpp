/* Phạm Nguyễn Thùy Dung
Mssv: 6151071003
tạo lớp MatHang ( tên ,số lượng, đơn giá) phương thức nhập xuất
xây dựng lớp HoaDon  gồm các thuộc tính:
    Tên hóa đơn
    danh sách các mặt hàng
    số lượng các mặt hàng 
    các phương thức: Nhập  và in thông tin cho mỗi hóa đơn
    tính tổng tiền mỗi hóa đơn trong đó 
    tiền mỗi mặt hàng = số lượng * đơn giá.
-   Nhập danh sách các hóa đơn
-   Đưa ra hóa đơn có tổng tiền lớn nhất(bé nhất)
-   Tìm kiếm một hóa đơn theo tên.
Mô tả bài toán
-Tên lớp: MH(mặt hàng)
          HD (hoá đơn)
-Thuộc tính:
private:
+ tmh :char (tên mặt  hàng)     
+ sl : int (số lượng)     
+ dg: float(đơn giá )    
+ thd : char (tên hoá đơn)     
+dsmh : char (danh sách mặt hàng)     
+ slmh : int (số lượng mặt hàng)
-Phương thức:
public:
+void nhap() 
+void In()
+float tongt(float *t, int n)
+ float tien()
*/
#include <iostream>
using namespace std;
class MH {
    private:
        string tmh;
        int sl;
        float dg;
    public:
        void nhap ();
        void In ();
        float tien ();
};
class HD :public MH {
    private:
        string thd;
        MH *dsmh;
        int slmh;
    public:
        void nhap ();
        void In ();
        // float tongt (float *t, int n);
        float tongt();
        string getTHD(){
            return thd;
        }
};
void MH::nhap(){
    fflush(stdin);
    cout <<"Nhap Ten Mat Hang: " ;
    getline(cin,tmh);
    cout <<"Nhap So Luong: " ;
    cin >> sl;
    cout <<"Nhap Don Gia: " ;
    cin >> dg;
}
void MH:: In(){

    cout <<"Ten: "<<tmh<<" ||So Luong: "<< sl<<" ||Don Gia: "<<dg<<endl;
}
float MH::tien(){
    return (float)sl*dg;
}
void HD::nhap(){
    fflush(stdin);
    cout<<"Ten Hoa Don: ";
    getline(cin, thd);
    cout<<"Nhap So Luong Mat Hang: "; 
    cin>>slmh;
    cout<<endl<<"Nhap Danh Sach Mat Hang !!! "<<endl;
    fflush(stdin);
    dsmh = new MH[slmh];
    for(int i = 0; i < slmh ; i++ ){
        cout<<endl<<"--- Hang Hoa Thu "<<i+1<<"---"<<endl;
        dsmh[i].nhap();
    }
}
void HD::In(){
    cout <<endl<<"*****Hoa Don: "<<thd<<endl;
    cout <<"!!! Danh Sach Mat Hang !!! "<<endl;
    for(int i = 0; i < slmh ; i++ ){
        cout<<endl<<"--- Hang Hoa Thu "<<i+1<<"---"<<endl;
        dsmh[i].In();
    }
    cout <<"Tong Tien: "<<tongt()<<endl;
}
// float HD::tongt(float*t, int n) {
//      int tong=0;
//         for (int i = 0; i < n ; i++){
//             tong += tien()+*(t+i);
//         }
//         return tong;
// }
float HD::tongt(){
    float tong = 0;
    for (int i = 0; i < slmh; i++ ){
        tong +=dsmh[i].tien();
    }
    return tong;
}
void timkiem(HD *a,int n){
    string temp;
    fflush(stdin);
    cout <<endl<<"Nhap Ten Can Tim: ";
    getline(cin,temp);
    for (int i = 0; i < n; i++){
        if (temp == a[i].getTHD()){
            a[i].In();
            break;
        }
        else{
            cout <<"Khong Co Hoa Don Trong Danh Sach !"<<endl;
            break;
        }
    }
}
void MaxBill(HD *a,int n){
    int dem = 0;
    float max = a[0].tongt();
    for (int i = 0; i < n; i++){
        if (max < a[i].tongt()){
            max = a[i].tongt();
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i].tongt()==max){
            a[i].In();
            break;
        }
    }
    
}
void MinBill(HD *a,int n){
    int dem = 0;
    float min = a[0].tongt();
    for (int i = 0; i < n; i++){
        if (min > a[i].tongt()){
            min = a[i].tongt();
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i].tongt()==min){
            a[i].In();
            break;
        }
    }
    
}
void Nhap(HD *hd,int n){
    for (int i = 0; i < n; i++ ){
        cout <<endl<< "\t\tHoa Don Thu "<<i+1<<endl;
        hd[i].nhap();
    }
}
void in(HD *hd,int n){
    for (int i = 0; i < n; i++ ){
        cout <<endl<< "\t\tHoa Don Thu "<<i+1<<endl;
        hd[i].In();
    }
}
int main (){
    // Khai báo hóa đơn dạng con trỏ
    HD *hd;
    int n;
    // float t;
    // nhập vào số lượng hóa đơn
    cout <<endl<< "Nhap So Luong Hoa Don : ";
    cin >> n;
    // cấp phát bộ nhớ
    hd = new HD[n];
    // Nhập thông tin hóa đơn
    Nhap(hd,n);
    // Xuất thông tin hóa đơn đã nhập
    cout<<endl<<"************************************"<<endl;
    in(hd,n);
    // hàm tìm kiếm hóa đơn theo tên
    timkiem(hd,n);
    // in ra hóa đơn có tổng tiền cao nhất
    cout<<endl<<"************************************"<<endl;
    cout <<"Hoa Don Co Tong Tien Cao Nhat !!!"<<endl;
    MaxBill (hd,n);
    // in ra hóa đơn có tổng tiền thấp nhất
    cout<<endl<<"************************************"<<endl;
    cout <<"Hoa Don Co Tong Tien Thap Nhat !!!"<<endl;
    MinBill (hd,n);
    // xóa bộ nhớ
    delete [] hd;
    return 0;
}