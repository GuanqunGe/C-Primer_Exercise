#ifndef DELETER_H
#define DELETER_H

#include <iostream>
#include <typeinfo>

template <typename T>
void DelFunc(T *p){
    std::cout << "Deleting " <<  typeid(p).name() << std::endl;
    delete p;
}

template <typename T>
class DeleteObj{
public:
    void operator()(T *p){
	std::cout << "DeleteObj: deleting " << typeid(p).name() << std::endl;
	delete p;
    }
};

#endif
