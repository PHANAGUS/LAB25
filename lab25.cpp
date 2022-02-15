#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber operator+(const ComplexNumber &c1,const ComplexNumber &c2){
	return ComplexNumber(c1.real+c2.real,c1.imag+c2.imag);
}

ComplexNumber operator-(const ComplexNumber &c1,const ComplexNumber &c2){
	return ComplexNumber(c1.real-c2.real,c1.imag-c2.imag);
}

//Write your code here
ComplexNumber operator*(const ComplexNumber &c1,const ComplexNumber &c2){
	return ComplexNumber((c1.real*c2.real)-(c1.imag*c2.imag),(c1.real*c2.imag)+(c1.imag*c2.real));
}

ComplexNumber operator/(const ComplexNumber &c1,const ComplexNumber &c2){
	return ComplexNumber((c1.real*c2.real + c1.imag*c2.imag) / (pow(c2.real,2)+pow(c2.imag,2)) , (c1.imag*c2.real - c1.real*c2.imag) / (pow(c2.real,2)+pow(c2.imag,2)));
}

bool operator==(const ComplexNumber &c1,const ComplexNumber &c2){
	if(c1.real == c2.real && c1.imag == c2.imag){
		return true;
	}else{
		return false;
	}
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2) + pow(imag,2));
}

double ComplexNumber::angle(){
	return atan2(imag,real) * (180/M_PI);
}

ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.real == 0){
		if(c.imag == 0){
			return os << "0";
		}else{
			return os << c.imag << "i";
		}
	}else{
		if(c.imag == 0){
			return os << c.real;
		}else if(c.imag > 0){
			return os << c.real << "+" << c.imag << "i";
		}else{
			return os << c.real << c.imag << "i";
		}
	}
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





