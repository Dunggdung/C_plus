#include <iostream>
using namespace std;

class Complex {
	private:
		float a, b;
	public:
		Complex();
		Complex(const Complex &x);
		void add();
		void display();
		friend Complex operator + (Complex x, Complex y);
		friend Complex operator - (Complex x, Complex y);
};

Complex::Complex() {
	a = 0;
	b = 0;
}

Complex::Complex(const Complex &x) {
	a = x.a;
	b = x.b;
}

void Complex::add() {
	cout << "Nhap Phan Thuc: "; cin >> a;
	cout << "Nhap Phan Ao: "; cin >> b;
	cout << endl;
}

void Complex::display() {
	if (b < 0)
		cout << a << b << "*i";
	else 
		cout << a << "+" << b << "*i";
}

Complex operator + (Complex x, Complex y) {
	Complex c;
	c.a = x.a + y.a;
	c.b = x.b + y.b;
	return c;
}

Complex operator - (Complex x, Complex y) {
	Complex c;
	c.a = x.a - y.a;
	c.b = x.b - y.b;
	return c;
}

int main () {
	Complex x, y;
    cout <<"Nhap so phuc x"<<endl;
	x.add();
    cout <<"Nhap so phuc y"<<endl;
	y.add();
	
    cout <<"Tong hai so phuc: ";
	x.display();
	cout << "+";
	y.display();
	cout << "=";
	(x+y).display();
	cout << endl;
	
    cout <<"Hieu hai so phuc: ";
	x.display();
	cout << "-";
	y.display();
	cout << "=";
	(x-y).display();
}
