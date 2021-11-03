/* Phạm Nguyễn Thùy Dung 6151071003
Nguyễn Minh Phúc 6151071084
Phạm Chí Hùng 6151071051*/
#include <iostream>
using namespace std;
class A{
    private:
    int x,y;
    public:
		A();
		A(int x,int y);
		A(const A &x);
		~A();
        friend istream& operator >> (istream &is,A& a);
        friend ostream& operator << (ostream &os,A a);
        // void operator > (A a);
        bool operator > (A a);
        A operator + (A a);
};
class B: public A{
    private:
    int z;
    public:
        B();
        B(int z);
        B(const B &b);
		~B();
        friend istream& operator >> (istream &is,B& b);
        friend ostream& operator << (ostream &os,B b);
        // void operator > (B b);
        bool operator > (B b);
        B operator + (B b);
};
A::A(){
    x = 0;
    y = 0;
}
A::A(int x, int y){
    this->x = x;
    this->y = y;
}
A::A(const A &a){
    x = a.x;
    y = a.y;
}
A::~A(){}
B::B(){
    z= 0;
}
B::B(int z){
    this->z = z;
}
B::B(const B &b){
    z=b.z;
}
B::~B(){}

istream& operator >> (istream &is,A& a){
    cout << "Nhap x : ";
    is >> a.x;
    cout << "Nhap y : ";
    is >> a.y; 
    return is;
}
ostream& operator << (ostream &os,A a){
    os <<"x = "<<a.x<<" y = "<<a.y<<endl;
    return os;
}
istream& operator >> (istream &is,B& b){
    cout << "Nhap z: ";
    is >> b.z; 
    return is;
}
ostream& operator << (ostream &os,B b){
    os <<"z = "<<b.z<<endl;
    return os;
}
// void A::operator > (A a){
// 	if(x > a.x && y > a.y)
// 		cout<<" Lon Hon !"<<endl;
// 	else{
// 		cout<<" Nho Hon Hoac Bang !"<<endl;
// 	}
// }
bool A::operator > (A a){
    return (x > a.x && y>a.y);
}
bool B::operator > (B b){
    return (z > b.z);
}
// void B::operator > (B b){
// 	if(z > b.z)
// 		cout<<" Lon Hon !"<<endl;
// 	else{
// 		cout<<" Nho Hon Hoac Bang !"<<endl;
// 	}
// }
A A::operator + (A a){
    A temp;
    temp.x = x+a.x;
    temp.y = y+a.y;
    return temp;
}
B B::operator + (B b){
    B temp;
    temp.z = z+b.z;
    return temp;
}
int main (){
    A a, a1;
    B b, b1;
    //nhap A
    cout <<"***Nhap A: "<<endl;
    cin >> a ;
    //Nhap A1
    cout <<"***Nhap A1: "<<endl;
    cin >> a1 ;
    //Nhap B
    cout <<"***Nhap B: "<<endl;
    cin >> b ;
    //Nhap B1
    cout <<"***Nhap B1: "<<endl;
    cin >> b1 ;
    //Xuat A,B
    cout << a ;
    cout << b ;
    //Toan tu so sanh
    if (a >a1){
    cout << "Lon Hon !"<<endl;
    }else{
    cout << "Nho Hon Hoac Bang !"<< endl;   
    }

    if (b>b1){
    cout << "Lon Hon !"<<endl;
    }else{
    cout << "Nho Hon Hoac Bang !"<< endl;   
    }
    //Toan tu cong
    cout <<endl<<"Gia tri a + a1: "<< a + a1<< endl;
    cout <<"Gia tri b + b1: "<< b + b1<< endl; 
    
    return 0;
}