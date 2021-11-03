#include <iostream>
using namespace std;
class a{
    private:
        int x,y;
    public:
        a();
        a(int x,int y);
        a(const a &a1);
        ~a();
    // toan tu nhap xuat so sanh +
    friend istream& operator >> (istream & is, a &a1);
    friend ostream& operator << (ostream & os,const a &a1 );
    bool operator > (const a &a1);
    a operator + (const a &a1);
};
class b : public a {
    private:
        int z;
    public:
        b();
        b(int x,int y,int z);
        b (const b &b1);
        ~b();
        friend istream& operator >> (istream &is,b& b1);
        friend ostream& operator << (ostream & os,const b& b1);
        bool operator > (b &b1);
        b operator + (b &b1);
};
a::a(){
    x=0;
    y=0;
}
a::a(int x,int y){
    this->x=x;
    this->y=y;
}
a::a(const a &a1){
    *this = a1;
}
a::~a(){}
istream& operator >> (istream & is, a &a1){
    cout << "Nhap x:";
    is >>a1.x;
    cout << "Nhap y:";
    is >> a1.y;
    return is;
}
ostream& operator << (ostream & os,const a &a1 ){
    os <<"x = " << a1.x<<endl;
    os <<"y = " << a1.y<<endl;
    return os;
}
a a::operator + (const a &a1){
    return a(x+a1.x,y+a1.y);
}
bool a::operator > (const a &a1){
    return (this->x>a1.x)?true:false;
}
b::b():a(){
    z = 0;
}
b::b(int x,int y,int z):a(x,y) {
    this->z = z;
}
b::b(const b &b1){
    *this = b1;
}
b::~b(){}
istream& operator >> (istream & is,b &b1){
    // goi tot toan tu nhap a
    //     a a1 = static_cast<a >(b1);
    a *a1 = static_cast<a *>(&b1);
    is >> *a1;
    cout <<"Nhap z: ";
    is >> b1.z;
    return is;
}
ostream& operator << (ostream & os,const b &b1){
    a a1 = static_cast<a>(b1);
    os << a1;
    os << "z = " << b1.z ;
    return os; 
}
b b::operator + (b &b1){
    //x + b1.x
    //y + b1.y
    //z + b1.z
    b t;
    a *a1 = static_cast<a *>(&b1);
    a *a2 = static_cast<a *>(this);
    a *t1 = static_cast<a *>(&t);
    *t1 = *a1 + *a2;
    t.z = z + b1.z;
    return t;
}
bool b::operator > (b &b1){
    a * a1 = static_cast<a *>(&b1);
    a * a2 = static_cast<a *>(this);
    if ( *a1 > * a2 && z >b1.z)
        return true;
    else
        return false;
    
    //if ( *a1 < * this && z >b1.z)
}
int main (){
    // b b1(1,2,3);
    // b b2(b1);
    b b1,b2 , b3;
    cout <<"Nhap b1: "<<endl;
    cin >>b1;
    cout <<"Nhap b2: "<<endl;
    cin >>b2;
    b3 = b1 + b2;
    cout <<"Sum "<<endl<<b3<<endl;
    // cout << b1;
    if (b1>b2){
    cout << "Lon Hon !"<<endl;
    }else{
    cout << "Nho Hon Hoac Bang !"<< endl;   
    }
    return 0;
}