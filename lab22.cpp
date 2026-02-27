#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

// --- New Code Starts Here ---

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double den = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / den, (imag * c.real - real * c.imag) / den);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    return (real == c.real && imag == c.imag);
}

double ComplexNumber::abs(){
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle(){
    return atan2(imag, real) * 180.0 / M_PI;
}

// Handling 'double op ComplexNumber' (Left-hand side is double)
ComplexNumber operator+(double s, const ComplexNumber &c){
    return ComplexNumber(s + c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c){
    return ComplexNumber(s - c.real, -c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c){
    return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c){
    return ComplexNumber(s, 0) / c;
}

bool operator==(double s, const ComplexNumber &c){
    return (s == c.real && c.imag == 0);
}

// Formatting for cout << ComplexNumber
ostream& operator<<(ostream &os, const ComplexNumber &c){
    if(c.real == 0 && c.imag == 0) return os << "0";
    if(c.real == 0) return os << c.imag << "i";
    if(c.imag == 0) return os << c.real;
    
    os << c.real;
    if(c.imag > 0) os << "+";
    return os << c.imag << "i";
}