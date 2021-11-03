#include<iostream>
using namespace std;
class A{
    private:
        int x;
    protected:
        int y; 
    public:
        int z;
};
// class B:public A{
//     private:
//         int v;
//     public:
//         void show();
// };
class B:protected A{
    private:
        int v;
    public:
        void show();
};
class C:public B{
    public:
        show(){
            cout<<y;
        }
};
void B::show(){
    cout <<y;
}
int main(){
    A a;
    B b;  
    C c;
    cout<<a.z;
    c.show();
    b.show();
    return 0;
}