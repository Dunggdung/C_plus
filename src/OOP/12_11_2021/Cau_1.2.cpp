// Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;
class Complex {
	private:
		float thuc, ao;
	public:
		Complex();
		void Nhap();
		void Xuat();
        Complex operator = (Complex x)
		friend Complex operator + (Complex x, Complex y);
		friend Complex operator - (Complex x, Complex y);
};
Complex::Complex() {
	thuc = 0;
	ao = 0;
}
void Complex::Nhap() {
	cout << "Nhap phan thuc: "; cin >> thuc;
	cout << "Nhap phan ao: "; cin >> ao;
	cout << endl;
}
void Complex::Xuat() {
	if (ao < 0)
		cout << thuc << ao << "*i";
	else 
		cout << thuc << "+" << ao << "*i";
}
Complex operator + (Complex x, Complex y) {
	Complex c;
	c.thuc = x.thuc + y.thuc;
	c.ao = x.ao + y.ao;
	return c;
}
Complex operator - (Complex x, Complex y) {
	Complex c;
	c.thuc = x.thuc - y.thuc;
	c.ao = x.ao - y.ao;
	return c;
}
int main () {
	Complex x, y;
	cout << "So phuc x "<< endl; x.Nhap();
	cout << "So phuc y "<< endl;y.Nhap();
	
    cout <<"So phuc x: ";
    x.Xuat();
    cout <<endl<<"So phuc y: ";
    y.Xuat();
    cout <<endl<<endl;

    cout<<"Tong 2 so phuc: ";
	x.Xuat();
	cout << " + ";
	y.Xuat();
	cout << " = ";
	(x+y).Xuat();
	cout << endl;
	
    cout<<endl<<"Hieu 2 so phuc: ";
	x.Xuat();
	cout << " - ";
	y.Xuat();
	cout << " = ";
	(x-y).Xuat();
}
