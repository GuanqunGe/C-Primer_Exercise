#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    //constructor
    HasPtr(const std::string &s = std::string()):
	ps(new std::string(s)), i(0){}
   
    //move constructor
    HasPtr(HasPtr &&hp) noexcept: ps(hp.ps), i(hp.i) {hp.ps = nullptr; }

    //copy constructor
    HasPtr(const HasPtr &in):ps(new std::string(*in.ps)), i(in.i){}

    //copy-assignment operator
    //1. define copy assignment using HasPtr type parameter
 /*  HasPtr &operator=(HasPtr rhs){
	swap(*this, rhs);
	return *this;
    }*/

    //2. define copy assignment using const HasPtr& type parameer
    HasPtr &operator=(const HasPtr &in){
	auto temp = new std::string(*in.ps);
 	delete ps;
	ps = temp; 
	i = in.i;
	return *this;
    }


    //move assignment
    HasPtr &operator=(HasPtr &&hp) noexcept{
 	if( this != &hp){
	    delete ps;
	    ps = hp.ps;
	    i = hp.i;
	    hp.ps = nullptr;
	}
 	return *this;
    }

    //To be honest, after implementing the copy/move assignment to use references, I don't think there is a big improvement on the efficiency. There are surely fewer pointer assignment in the operation, but the old copy and swap operator have the same amount of memory allocation as new copy/move assignment. Does pointer assignment hurt performance that bad? 

    //compare operator
    bool operator<(const HasPtr &in){
	return *ps < *in.ps;
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

    std::vector<HasPtr> vec;
    vec.push_back(std::string("World"));
    vec.push_back(HasPtr("Hey"));
    vec.push_back(HasPtr("Iris!"));

    std::vector<std::string> vstr{"Hey", "Jenie","Tesla",  "Kathryn", "Linda", "Mindy", "Nate", "Oops", "Peter", 
				"Queen", "Ryan", "Steve", "Unique", "Vivian", "Wow", "Zac", "Xing", "Y"};
    for(auto &s: vstr)
	vec.push_back(HasPtr(s));

    //swap is only called twice on this huge vector..
    std::sort(vec.begin(), vec.end());
    return 0;
}
