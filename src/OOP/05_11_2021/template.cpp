#include <iostream>
using namespace std;
template <class Type>
class A {
    private:
        Type x;
        Type y;
    public:
    A (Type x, Type y){
        this->x = x;
        this->y = y;
    }
    void hoandoi (){
        Type temp;
        temp = x;
        x = y;
        y = temp;
    }
    void xuat (){
        cout <<"x = "<<x<<endl;
        cout <<"y = "<<y<<endl<<endl;
    }
};
int main (){
    A <float> a(3.5,7.0);
    A <int> a1(3,4);

    a.xuat();
    a1.xuat();

    a.hoandoi();
    a.xuat();
    return 0;
}