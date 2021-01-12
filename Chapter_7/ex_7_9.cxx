#include <string>
#include <iostream>

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

std::istream &read(std::istream &ins, Person &inp){
    ins >> inp.name >> inp.address;
    return ins;
}

std::ostream &print(std::ostream &out, const Person &inp){
    out << inp.Name() << " " <<  inp.Address() << " ";
    //out << inp.name << " " <<  inp.address << " ";
    return out;
}

int main(){
    Person A;
    print(std::cout, A) << std::endl;

    read(std::cin, A);
    print(std::cout, A) << std::endl;
    return 0;
}
