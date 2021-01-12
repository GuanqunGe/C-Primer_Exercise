#include <iostream>

class X{
    public:
    int i;
    int j;
    X(int val): j(val), i(j) {}  //why doesn't the compiler throw an error?? at the point of initializing variable i, j is not defined yet.
};

int main(){
    X obj(3);
    std::cout << obj.i << " " << obj.j << std::endl;

    int m = n; //compilation error: n not defined
    std::cout << m << std::endl;
    return 0;
}
