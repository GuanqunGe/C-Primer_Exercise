#include <string>

using std::string;

struct Person{
    //members
    string name;
    string address; 

    //member functions


    //Name() and Address() functions should be const member function since they don't change the member of the class, also being const member function also allows them to be used on const class object.
    string Name() const {return name;}
    string Address() const {return address;} 



};

int main(){
    return 0;
}
