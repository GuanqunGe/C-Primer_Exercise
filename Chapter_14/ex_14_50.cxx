#include <iostream>

struct LongDouble{
    LongDouble (double=0.0) { std::cout << "LongDouble(double)" << std::endl;}
    operator double() {
	std::cout << "LongDouble::operator double()" << std::endl;
	return 1.0;
    }
    operator float(){
	std::cout << "LongDouble::operator float() "<<std::endl;
	return 1.0;
    }
};

void calc(int){  std::cout << "calc(int) " << std::endl; }
void calc(LongDouble) {std::cout << "calc(LongDouble)" << std::endl; }

int main(){
    LongDouble ldObj;
    //int ex1 = ldObj;
    float ex2 = ldObj;

    double val;
    calc(val);
    return 0;
}

// ex_14_50
// for ex1, since neither conversion operator of LongDouble returns exact type of int, both are viable, but both requires standard conversion
// so, the call will be ambigious thus illegal
// for ex2, since the conversion operator LongDouble::operator float() returns exactly float type, so it will be the best fit and thus legal


// ex_14_51
// for calc(val), if it calls the calc(int) version, then standard conversion is needed when the argument of type int is initialized
// if it calls the calc(LongDouble) version, given that LongDouble has a constructor that takes a double, local parameter in calc(LongDouble)
// functino will be copy constructed by temporary object constructed by LongDouble(double)
// So the best viable function is calc(LongDouble)
// ---> Hoever, it's the calc(int) which is called.
// I guess I know why, calling cal(int) requires arithmetic conversion, while calling calc(LongDouble) requires class-type conversion (page. 245)
