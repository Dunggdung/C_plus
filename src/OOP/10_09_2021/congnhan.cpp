#include<iostream>
#define Max 15
using namespace std;

struct CongNhan {
    char ten [25];
    int namsinh;
    int gio;
};
void nhap (CongNhan *cn);
void xuat (CongNhan *cn);
void xuat (CongNhan *cn,int n);
void enter (CongNhan *cn, int n);
void sapxep (CongNhan *cn, int n);
int main (){
    int n;
    CongNhan *cn;
    cn = new CongNhan[n];
    do {
        cout << "Nhap So Cong Nhan: "; 
        cin >> n;
            if (n <= 0 || n > Max){
                cout << "Vui Long Nhap Lai!" << endl;
                cout << "Nhap So Cong Nhan: "; 
                cin >> n;
            }
    }while (n <= 0 || n > Max );
    enter (cn,n);
    xuat (cn,n);
    sapxep (cn,n);
    cout << "Danh Sach Cong Nhan Sau Sap Xep" << endl;
    xuat (cn,n);
    if (cn != NULL)
    delete [] cn;
    return 0;
}
void nhap (CongNhan *cn){
    
    cout << "Nhap Ten: ";
    cin >> cn->ten;
    cout << "Nhap Nam Sinh: ";
    cin >> cn->namsinh;
    cout << "Nhap Gio Lam: ";
    cin >> cn->gio;
}
void enter (CongNhan *cn, int n){
    for(int i=0; i < n; i++){
        cout << "***Nhap Thong Tin Cong Nhan "<< i+1 <<endl;
        nhap (cn+i);
    }
}
void xuat (CongNhan *cn){
    cout << "Ten: "<< cn->ten << " ||Nam Sinh: " << cn->namsinh << " ||Gio Lam:" << cn->gio << endl;
}
void xuat (CongNhan *cn,int n){
    for(int i=0; i < n; i++){
        cout << "***Thong Tin Cong Nhan "<< i+1 <<endl;
        xuat (cn+i);
    }
}
void sapxep (CongNhan *cn, int n){
    CongNhan *temp;
    temp = new CongNhan[n];
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if((cn+i)->gio > (cn+j)->gio)
                *temp = *(cn+i);
                *(cn+i)= *(cn+j);
                *(cn+j)= *temp;
        }
    }
}