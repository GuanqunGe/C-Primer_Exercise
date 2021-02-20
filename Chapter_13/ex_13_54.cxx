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
    HasPtr(HasPtr &&hp): ps(hp.ps), i(hp.i) {hp.ps = nullptr; }

    //copy constructor
    HasPtr(const HasPtr &in):ps(new std::string(*in.ps)), i(in.i){}

    //copy-assignment operator
    //1. define copy assignment using HasPtr type parameter
    HasPtr &operator=(HasPtr rhs){
	std::cout << "copy assignment" << std::endl;
	swap(*this, rhs);
	return *this;
    }

    //2. define copy assignment using const HasPtr& type parameer
   /* HasPtr &operator=(const HasPtr &in){
	auto temp = new std::string(*in.ps);
 	delete ps;
	ps = temp; 
	i = in.i;
	return *this;
    }


    //move assignment
    HasPtr &operator=(HasPtr &&hp){
 	if( this != &hp){
	    delete ps;
	    ps = hp.ps;
	    i = hp.i;
	    hp.ps = nullptr;
	}
 	return *this;
    }
*/
    //compare operator
    bool operator<(const HasPtr &in){
	return *ps < *in.ps;
    }

    //destructor
    ~HasPtr(){
	delete ps; //ps is ordinary pointer bound to dynamically allcated object
    }

    const std::string &GetContent() const {
	//return (ps ? *ps : "None" );  //wrong, can not return reference to a temporary object 
	return *ps; 
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
    std::cout << "Swap two HasPtrs:" << ( lhs.ps ? *lhs.ps : "None") << " " << (rhs.ps ? *rhs.ps: "None" ) <<  std::endl;
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
    //somehow, sort algorithm also uses the assignment operator
    //and i STILL dont' understand how sort() algorithm works.
    std::cout << "\n\n end of sort\n\n" << std::endl;

    for(const auto &hp : vec)
	std::cout << hp.GetContent() << " ";
    std::cout << std::endl;

    HasPtr a = std::string("Feb");
    HasPtr b;
    b = a;
    a = std::move(b);

    //if we define the move assignment but also keep the copy-and-swap operator, then when we do assignment,
    //if the right hand operand is an lvalue, then copy-and-swap operator will be viable.
    //if the right hand operand is an rvalue reference, then both copy-and-swap operator and move assignment operator
    //are viable and can be matched, thus it will be an ambiguous call.
    return 0;
}
