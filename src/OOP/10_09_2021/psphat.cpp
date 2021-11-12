#include<iostream>
using namespace std;
struct a
{
    int tu;   //tu so
    int mau; //mau so
};
void inputphanso(phanso &a)
{
    cout<<"Enter tu: ";
    cin>>a.tu;
    do
    { //mau > 0
        cout<<"Enter mau: ";
        cin>>a.mau;
        if (a.mau == 0)
        {
            cout<<"Enter mau again!";
        }
    } while (a.mau == 0);
}
void outputphanso(phanso a)
{
    cout<<endl<<a.tu<<"/"<<a.mau;
}
int greatestCommonDivisor(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
void compactphanso(phanso &a)
{   //rut gon phan so
    int c = greatestCommonDivisor(a.tu, a.mau);
    a.tu = a.tu / c;
    a.mau = a.mau / c;
}
void check(phanso a){
    // kiểm tra phân số âm
    if(a.tu>0){
        if(a.mau<0) cout<<"Negative a"<<endl;
        else cout<<"Positive a"<<endl;
    }
    else{
        if(a.mau<0) cout<<"Positive a"<<endl;
        else cout<<"Negative a"<<endl;
    }
}
phanso tong(phanso first_a, phanso second_a)
{
    //tong 2 phan so
    phanso total;
    total.tu = (first_a.tu * second_a.mau) + (second_a.tu * first_a.mau);
    total.mau = first_a.mau * second_a.mau;
    if(total.tu!=0) compactphanso(total);
    return total;
}
phanso hieu(phanso first_a, phanso second_a)
{
    //hieu 2 phan so
    phanso minus;
    minus.tu = (first_a.tu * second_a.mau) - (second_a.tu * first_a.mau);
    minus.mau = first_a.mau * second_a.mau;
    if(minus.tu!=0) compactphanso(minus);
    return minus;
}
phanso tich(phanso first_a, phanso second_a)
{
    //Tich 2 phan so
    phanso times;
    times.tu = first_a.tu * second_a.tu;
    times.mau = first_a.mau * second_a.mau;
    if(times.tu!=0) compactphanso(times);
    return times;
}
phanso thuong(phanso first_a, phanso second_a)
{
    //Thuong 2 phan so
    phanso divides;
    divides.tu = first_a.tu * second_a.mau;
    divides.mau = first_a.mau * second_a.tu;
    if(divides.tu!=0) compactphanso(divides);
    return divides;
}
int sosanh(phanso first_a, phanso second_a)
{
    //So sanh 2 phan so
    int result = -1;
    if (first_a.mau == second_a.mau)
    {
        if (first_a.tu > second_a.tu)
        {
            result = 0;
        }
        else if (first_a.tu < second_a.tu)
        {
            result = 1;
        }
    }
    else
    {
        if (first_a.mau > second_a.mau)
        {
            result = 1;
        }
        else if (first_a.mau < second_a.mau)
        {
            result = 0;
        }
    }
    return result;
}
void outputsosanh(phanso first_a, phanso second_a)
{
    switch (sosanh(first_a, second_a))
    {
    case 0:
        cout<<endl<<"-First a is bigger than second a";
        break;
    case 1:
        cout<<endl<<"-First a is smaller than second a";
        break;
    default:
        cout<<endl<<"-Two as are equal";
    }
}
int main()
{
    phanso first_a, second_a;
    inputphanso(first_a);  //phan so 1
    inputphanso(second_a); //phan so 2
    outputphanso(first_a);
    outputphanso(second_a);
    cout<<endl<<"first a is: ";
    check(first_a);
    cout<<endl<<"second a is: ";
    check(second_a);
    phanso total = tong(first_a, second_a);
    cout<<endl<<"Summation of 2 as is: ";
    outputphanso(total);
    phanso minus = hieu(first_a, second_a);
    cout<<endl<<"Subtraction of 2 as is: ";
    outputphanso(minus);
    phanso times = tich(first_a, second_a);
    cout<<endl<<"Subtraction of 2 as is: ";
    outputphanso(times);
    phanso devides = thuong(first_a, second_a);
    cout<<endl<<"Devision of 2 as is: ";
    outputphanso(devides);
    outputsosanh(first_a, second_a);
}