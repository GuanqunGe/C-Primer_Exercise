// Ok, so the main difference here between unique_ptr and shared_ptr is that
// unique_ptr need to have a second (default) typename parameter that takes function pointer or function object as part of its type
// while shared_ptr can change its deleter function/function object easier through reset or during initialization of a shared_ptr
//  For now, my biggest question is, how to convert function pointer type to function object type?

#include <iostream>
#include <string>
#include "SharedPtr.h"
#include "UniquePtr.h"
#include "Deleter.h"

void test_SharedPtr(){
    //test on int type
    {
        SharedPtr<int> ip = new int(1);
	std::cout << *ip << ", usr count: " << ip.use_count() << std::endl;
	ip.reset();
        std::cout << "usr_count: " << ip.use_count() <<std::endl;
	ip.reset(new int(5), DelFunc<int>); //function name includes template argument
	std::cout << *ip << ", usr count: " << ip.use_count() << std::endl;
    }

    //test on container type
    {
	SharedPtr<std::string> sp(new std::string("Hello"), DelFunc<std::string>);
    	std::cout << *sp << ", size: " << sp->size() << std::endl;
    	std::cout << "is sp unique? " << ( sp.unique() ? "true" : "false" ) << std::endl;
    }

    //test on function object as deleter, instead of function
    SharedPtr<int> ip1(new int(1), DeleteObj<int>());
    ip1.reset();
}

void test_UniquePtr(){
    //test on int type, and default delete function
    {
	UniquePtr<int> ip =new int(1);  // ok, i had thought this is because we define move consttructor
					// however, since the constructor that takes  a built-in pointer is not explicit
					// even if I didn't define move constructor, this line should work as well
					// but, in fact, if I didn't define move constructor, this line causes compilation error.
	//UniquePtr<int> ip(new int(1));
 	std::cout << (ip ? "valid pointer" : "null pointer") << ", content: " << *ip << std::endl;
    }

    //test on string type
    {
	UniquePtr<std::string> sp = new std::string("Pi Day");
	std::cout << *sp << std::endl;
   	sp.reset();
	std::cout << (sp ? "valid pointer" : "null pointer") << std::endl;
	sp.reset(new std::string("May the fourth"));
        std::cout << (sp ? "valid pointer" : "null pointer") << ", content: " << *sp << std::endl;
    }

    //test on function pointer and function object
    {
	UniquePtr<int, decltype(DelFunc<int>) *> ip2(new int(8), DelFunc<int>);
    }

    {
	UniquePtr<std::string, DeleteObj<std::string>> sp2(new std::string("Hey"), DeleteObj<std::string>());
    }
}

int main(){
  
    //test_SharedPtr();
    test_UniquePtr();
    return 0;
}
