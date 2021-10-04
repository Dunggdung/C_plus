/*Viết chương trình tương đương với máy tính đơn giản
có những chức năng như: 
+ tính cộng , trừ, nhân, chia.
+ hiển thị menu để nhập sự lựa chọn.*/
#include<iostream>
#include <conio.h>
using namespace std;
int total (int a,int b);
float divide (int a,int b);
int subtract (int a,int b);
int multiply (int a,int b);
void menu (int a,int b);
int main (){
    int a,b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    menu (a,b);
    return 0;
}
int total (int a,int b){
    return a+b;
}
float divide (int a,int b){
    return float(a/b); 
}
int subtract (int a,int b){
    return a-b;
}
int multiply (int a,int b){
    return a*b;
}
void menu (int a,int b){
    int choice;
    char k,c;
    do{
        cout <<endl<< "*********************MENU********************" <<endl;
        cout << "1.     Phép cộng "<<endl;
        cout << "2.     Phép trừ "<<endl;
        cout << "3.     Phép nhân "<<endl;
        cout << "4.     Phép chia "<<endl;
        cout << "Nhập Lựa Chọn Của Bạn: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << a << " + " << b << " = " << total(a,b) << endl;
                break; 
            case 2: cout << a << " - " << b << " = " << subtract(a,b) << endl;
                break; 
            case 3: cout << a << " * " << b << " = " << multiply(a,b) << endl;
                break; 
            case 4: cout << a << " : " << b << " = " << divide(a,b) << endl;
                break; 
            default: cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại" << endl;
                break; 
        }
        cout << "Bạn muốn thoát ? (esc)" << endl;
        k = getch();
        c = k;
    }while(c != 27);
}