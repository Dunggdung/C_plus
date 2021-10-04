#include<iostream>
using namespace std;
typedef struct phanso {
    int tu;
    int mau;
}ps;
void enter (ps &a,ps &b);
void prints (ps a,ps b);
void exit (ps a);
int UCLN (int a, int b){
int main () {
    struct phanso;
    ps a,b;
    enter (a,b);
    prints (a,b);
    return 0;
}
void enter (ps &a,ps &b){
    cout << "***Nhap Phan So 1 "<<endl;
    cout << "Nhap Tu So: ";
    cin >> a.tu;
    cout << "Nhap Mau So: ";
    cin >> a.mau;
    cout << "***Nhap Phan So 2 "<<endl;
    cout << "Nhap Tu So: ";
    cin >> b.tu;
    cout << "Nhap Mau So: ";
    cin >> b.mau;
}
void prints (ps a,ps b){
    cout << "Phan So 1: "<<a.tu << "/" << a.mau << endl;
    cout << "Phan So 2: "<<b.tu << "/" << b.mau;
}
// void exit (ps a){
//     cout << "Phan So : "<<a.tu << "/" << a.mau << endl;
// }
// int UCLN (int a, int b){
//     a = abs(a);
//     b = abs(b);
//     while (a != b)
//     {
//         if (a > b)
//             a = a - b;
//         else
//             b = b - a;
//     }
//     return a;
// }
// void rutgon (ps &a){   //rut gon phan so
//     int c = rutgon (a.tu, a.mau);
//     a.tu = a.tu / c;
//     a.mau = a.mau / c;
// }