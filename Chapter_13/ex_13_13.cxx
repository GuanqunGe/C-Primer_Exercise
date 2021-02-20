#include <iostream>
#include <vector>
#include <memory>

struct X{

    //constructtor
    X(){std::cout << "X()" << std::endl;}
    //copy constructor
    X(const X &){std::cout << "X(const X&)" << std::endl;}
    //copy assignment
    X &operator=(const X &){
	std::cout << "X &operator=(const X&)" << std::endl;
	return *this; 
    }

    //destructor
    ~X(){ std::cout << "~X()"<<std::endl; }
};

int main(){

   X item1;
   X item2 = item1;
   X item3(item1);
   item2 = item3;

   std::cout << "\n begin vector: " << std::endl;
   {
       std::vector<X> vec;
       std::cout << "capacity: " << vec.capacity()<<std::endl;
       vec.push_back(X());   
       std::cout << "capacity: " << vec.capacity()<<std::endl;

       vec.push_back(item2); //reallocation happens
   }

   std::cout << "\n end vector\n" << std::endl;

   std::cout << "\n begin shared_ptr:" << std::endl;
   {
        std::shared_ptr<X> ptr = std::make_shared<X>();
	*ptr = item1;
   }

   std::cout << "end shared_ptr\n" << std::endl;

   return 0;
}
