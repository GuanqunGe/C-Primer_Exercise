#include <iostream>

int main(){
    
    int i = 1, j = 2;
    int &i1 = i, &j1 = j;
    i1 = 5, j1  = 10;;
    std::cout << "i now is " << i << ", i1 " << i1 << std::endl;
    std::cout << "j now is " << j << ", j1 " << j1 << std::endl;

    //int &k1 = 7;  //can not initialize non-const reference from an rvalue.
    const int &k1 = 7;  //ok to initialize a const reference from an rvalue, because a reference to const can't change the object it bounds to 
    std::cout << "k1 is " << k1 << std::endl;

    double d = 4.5;
    const double &d1 = d;
    const int &di = d;
    std::cout << "value of const double is " << d1 << ", value of const int is " << di << "( expect 4.5, 4) " << std::endl;
    

    d++;
    std::cout << "value of const double is " << d1 << ", value of const int is " << di << " (expect 5.5, 5)" <<  std::endl;

    d = 6.5;
    std::cout << "value of const double is " << d1 << ", value of const int is " << di << " (expect 6.5, 6) " << std::endl;



    //const int c1, &r1 = c1;  //const object needs to be initialized 
    const int c1 = 3, &r1 = c1; 
    std::cout << "c1 is " << c1 << ", r1 is " << r1 << std::endl; 
    
    return 0;


}
