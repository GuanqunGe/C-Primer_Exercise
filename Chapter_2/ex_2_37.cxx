#include <iostream>

int main(){

   int a = 3, b = 4;
   decltype(a) c = a;   //c is int
   decltype(a = b) d = a;   // d is int &
   std::cout << "a is "<< a << ", b is "<< b << ", c is "<< c<< ", d is " << d << std::endl;

   d++;
   c += 2;
   std::cout << "a is "<< a << ", b is "<< b << ", c is "<< c<< ", d is " << d << std::endl;
  
  return 0;
}
