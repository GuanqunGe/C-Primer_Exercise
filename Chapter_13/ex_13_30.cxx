#include <iostream>
#include <string>
#include <utility>

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    //constructor
    HasPtr(const std::string &s = std::string()):
	ps(new std::string(s)), i(0){}

    //copy constructor
    HasPtr(const HasPtr &in):ps(new std::string(*in.ps)), i(in.i){}

    //copy-assignment operator
    HasPtr &operator=(const HasPtr &in){
	auto temp = new std::string(*in.ps);
 	delete ps;
	ps = temp; 
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

inline
void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "Swap two HasPtrs" << std::endl;
}


int main(){

    HasPtr p1("Hello");

    HasPtr p2 = std::string("World");

    HasPtr p3 = p1;

    HasPtr p4;
    swap(p4, p1);

    return 0;
}
