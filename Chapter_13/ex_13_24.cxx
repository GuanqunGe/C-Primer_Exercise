#include <string>

class HasPtr{
public:
    //constructor
    HasPtr(const std::string &s = std::string()):
	ps(new std::string(s)), i(0){}

    //copy constructor
    HasPtr(const HasPtr &in):ps(new std::string(*in.ps)), i(in.i){}

    //copy-assignment operator
    HasPtr &operator=(const HasPtr &in){
        std::string *newp = new std::string(*in.ps);
 	delete ps;
	ps = newp;
	i = in.i;
	return *this;
    }

    //destructor
    ~HasPtr(){
	delete ps; //ps is ordinary pointer bound to dynamically allcated object
    }

private:
    std::string *ps;
    int i;
};

int main(){

    HasPtr p1("Hello");

    //HasPtr p2 = "World"; //Wrong: conversion from ‘const char [6]’ to non-scalar type ‘HasPtr’ requested

    HasPtr p3 = p1;

    HasPtr p4;
    p4 = p1;

    return 0;
}

//If we didn't define a destructor, then the dynamically allocated memory will be lost. 
//For short program this won't necessarily lead to a problem, but the program will crash for long run.
//If we didn't define a copy constructor, the newly created object will point to the 
//same memory as the copied object
