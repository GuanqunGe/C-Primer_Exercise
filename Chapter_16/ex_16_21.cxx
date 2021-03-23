#include <iostream>
#include <string>
#include <memory>

class DebugDelete{
public:
    DebugDelete(std::ostream &s = std::cerr): os(s){}
    template <typename T> void operator()(T *p) const{
	os << "Delete pointer" << std::endl;
	delete p;
    }
private:
    std::ostream &os;
};

void test_DebugDelete(){
    int *ip = new int(5);
    DebugDelete dl; 
    dl(ip);  //instantiates void DebugDelete::operator()<int>(int *) 


    double *dp = new double; //default initialzied
    dl(dp); //instantiates void DebugDelete::operator()<double>(double *);

    std::string *sp = new std::string(); //value initialized
    DebugDelete()(sp);
}


int main(){

    test_DebugDelete();

    //use user-defined deleter function
    std::unique_ptr<int, DebugDelete> ip(new int(5), DebugDelete());
    return 0;    
}
