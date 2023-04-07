#include<iostream>
#include<cmath>
using namespace std;
class Rational {
public:	int numerator;
	int denominator;
	Rational(int A, int B) {
		numerator = A;
		denominator = B;
	}
	friend int gcd(int, int);
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);
	Rational operator++();
	void operator=(Rational&);
	friend istream& operator>>(istream& , Rational& );
	friend ostream& operator<<(ostream&, const Rational&);
	void deal(int&, int&);
};
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
void Rational::deal(int& a, int& b) {
	int g = gcd(a, b);
	a /= g;
	b /= g;
	if (a < 0) {
		b *= (-1);
		a *= (-1);
	}
}
Rational Rational::operator+(const Rational& A) {
	Rational B(0,0);
	B.denominator =this->denominator* A.denominator;
	B.numerator =this->numerator*A.denominator+this->denominator*A.numerator ;
	deal(B.denominator, B.numerator);
	return B;
}
Rational Rational::operator-(const Rational& A) { 
	Rational B(0, 0);
	B.denominator = this->denominator * A.denominator;
	B.numerator = this->numerator * A.denominator - this->denominator * A.numerator;
	deal(B.denominator, B.numerator);
	return B;
}
Rational Rational::operator*(const Rational& A) {
	Rational B(0, 0);
	B.denominator = this->denominator * A.denominator;
	B.numerator = this->numerator * A.numerator;
	deal(B.denominator, B.numerator);
	return B;
}
Rational Rational::operator/(const Rational& A) {
	Rational B(0, 0);
	B.denominator = this->denominator * A.numerator ;
	B.numerator = this->numerator * A.denominator;
	deal(B.denominator, B.numerator);
	return B;
}
Rational Rational::operator++(){
	Rational B(0,0);
	B.denominator = this->denominator;
	B.numerator = this->denominator + this->numerator;
	deal(B.denominator, B.numerator);
	return B;
}
void Rational::operator=(Rational& A){
	Rational B(0, 0);
	int temp = 0;
	temp = this->denominator;
	this->denominator = this->numerator;
	this->numerator = temp;
	temp = A.denominator;
	A.denominator=A.numerator;
	A.numerator = temp;
}
istream& operator>>(istream& in, Rational& A){
	in >> A.numerator >> A.denominator;
	return in;
}
ostream& operator<<(ostream& out, const Rational &A) {
	if (A.denominator == 1) {
		out << A.numerator;
		return out;
	}
	out << A.numerator << '/' << A.denominator;
	return out;
}
int main() {
	Rational a(0,0), b(0,0);
	cin >> a >> b;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << ++a <<" "<<++b << endl;
	a = b;
	cout << a << " " << b << endl;
	return 0;
}