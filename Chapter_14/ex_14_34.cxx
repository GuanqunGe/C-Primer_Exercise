#include <iostream>

struct Conditional{
    int operator()(bool exp1, int out1, int out2) const{
	return exp1 ? out1 : out2;
    }
};

int main(){

    Conditional f;
    std::cout << f( 1>0, 1, 0) << std::endl;
    std::cout << f( 5 < 10, 10, 5) << std::endl;
    return 0;
}
