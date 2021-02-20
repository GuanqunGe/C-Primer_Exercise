#include <string>

class HasPtr{
public:
    //constructor
    HasPtr(const std::string &s = std::string()):
	ps(new std::string(s)), i(0){}

    //copy constructor
    HasPtr(const HasPtr &in):ps(new std::string(*in.ps)), i(in.i){}
private:
    std::string *ps;
    int i;
};

int main(){

    HasPtr p1("Hello");

    //HasPtr p2 = "World"; //Wrong: conversion from ‘const char [6]’ to non-scalar type ‘HasPtr’ requested

    HasPtr p3 = p1;
    HasPtr p4(p1); //this is also copy constructor
 
    return 0;
}
