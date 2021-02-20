#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s=std::string()):
	ps(new std::string(s)),i(0), use(new std::size_t(1)){}

    //copy constructor
    HasPtr(const HasPtr& ip):ps(ip.ps), i(ip.i),use(ip.use){ ++*use; }

    //copy assignment
    HasPtr &operator=(const HasPtr &ip){
	++*ip.use;
  	--*use;
	if(*use == 0){
	    delete ps;
	    delete use;
	}

        ps = ip.ps;
	i = ip.i;
	use = ip.use;
	return *this;
    }

    //destructor
    ~HasPtr(){
	--*use;
	if(*use == 0){  //can combine this line with the last line into if( --*use == 0)
	    delete ps;
	    delete use;
	}
    }

    size_t GetUseCount() const {return *use; }
private:
    std::string *ps;
    int i;
    std::size_t *use; //number of use count    
};


int main(){

    HasPtr A("Hello");

    HasPtr B = std::string("World"); //OK.
    //HasPtr B = "World"; //error: conversion from ‘const char [6]’ to non-scalar type ‘HasPtr’ requested
    HasPtr C(A);
    {
	HasPtr D = B;
    }
    std::cout << A.GetUseCount() << std::endl;
    std::cout << B.GetUseCount() << std::endl;
    return 0;
}
