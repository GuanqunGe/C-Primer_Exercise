#include <iostream>

struct SmallInt{
     friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int n=0):val(n){}
    operator int() const {return val; }
private:
    std::size_t val;
};

SmallInt operator+(const SmallInt&, const SmallInt&){
    return SmallInt();
}


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

   LongDouble operator+(const SmallInt&){
	std::cout << "LongDougle operator+(const SmallInt&)" << std::endl;
   }
};

LongDouble operator+(LongDouble&, double){
    std::cout << "LongDouble operator+(LongDouble&, double)" << std::endl;
    return LongDouble();
}

int main(){

    SmallInt si;
    LongDouble ld;
    //ld = si + ld;
    ld = ld + si;

    //ex_14_53
    //double d = si + 3.14;  // ambigious call, both built-in operator+(int, double) and SmallInt operator+(const 
    			     // SmallInt&, const SmallInst&) are equally good
    //double d = static_cast<int>(si) + 3.14;  //use built-in operator
    double d= si + SmallInt(3.14);  //use SmallInt operator+(const SmallInt&, const SmallInst&)
    return 0;
    
}
/*
 * ex_14_52
 * One important thing to remember is that, the compiler only allows ONE, "USER-DEFINED" conversion at a time.
for ld = si + ld;
Candidate function:
	SmallInt::operator+()
	LongDougle operator+(const SmallInt&);
	LongDouble operator+(longDouble&, double);
	built-in operator+()
Viable function:
 	built-in operator+(): si -> int, ld-> float/double, and then the result of the addition will be used to 
        construct a LongDouble temporary object, which will be copy-assigned to ld.

This expression is ambigious, as two built-in operator are equally good.


for ld = ld + is;
Candicate function:
	LongDouble::operator+()
	LongDouble operator+(LongDouble&, double);
	SmallInt::operator+()
 	built-in operator+
Viable functoin:
	LongDouble::operator+()  -> perfect match
	LongDouble operator+(LongDouble&, double);  -> si -> int -> double.
	built-in operator+  --> si -> int, ld -> float/double, and then do the addtion, finally create a temporary 
        object of LongDouble and ssign to ld.

Best-Match:
        LongDouble::operator+()

*/
