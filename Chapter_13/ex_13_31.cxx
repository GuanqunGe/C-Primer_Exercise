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
