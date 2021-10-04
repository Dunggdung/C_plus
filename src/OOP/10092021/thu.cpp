#include<iostream>
#include <conio.h>
using namespace std;
void menu (int a);
int main (){
    int choice;
    char k,c;
    do{
        cout <<endl<< "*********************Lich********************" <<endl;
        cout << "1.     Chu Nhat "<<endl;
        cout << "2.     Thu Hai "<<endl;
        cout << "3.     Thu Ba "<<endl;
        cout << "4.     Thu Tu "<<endl;
        cout << "5.     Thu Nam "<<endl;
        cout << "6.     Thu Sau "<<endl;
        cout << "7.     Thu Bay "<<endl;
        cout << "Nhap so tuong ung voi thu trong tuan: " ;
        cin >> choice;
        switch (choice) {
            case 1: cout << "1.     Chu Nhat "<<endl;
                break; 
            case 2: cout << "2.     Thu Hai "<<endl;
                break; 
            case 3: cout << "3.     Thu Ba "<<endl;
                break; 
            case 4: cout << "4.     Thu Tu "<<endl;
                break; 
            case 5: cout << "5.     Thu Nam "<<endl;
                break;
            case 6: cout << "6.     Thu Sau"<<endl;
                break; 
            case 7: cout << "7.     Thu Bay"<<endl;
                break; 
            default: cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại" << endl;
                break; 
        }
        cout << "Bạn muốn thoát ? (esc)" << endl;
        k = getch();
        c = k;
    }while(c != 27);
    return 0;
}
