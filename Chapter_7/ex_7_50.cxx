#include <string>
#include <iostream>

using std::string;

struct Person;
std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);


struct Person{
    private: 
    //members
    string name;
    string address; 


    public:  
    //constructor
    Person()=default;
 
    //to be safe, if there is any function that takes Person, or const Person & as parameter, I should declare my 1-parameter constructors as explicit.
    explicit Person(const string &inname):name(inname){}
    Person(const string &inname, const string &inadd):name(inname), address(inadd){}
    explicit Person(std::istream &is){  read(is, *this);    }



    //member functions

    //Name() and Address() functions should be const member function since they don't change the member of the class, also being const member function also allows them to be used on const class object.
    string Name() const {return name;}
    string Address() const {return address;} 

    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, const Person&);


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
    Person B("Mary");
    Person C("Dan","dan@gmail.com");
    Person D(std::cin);

    print(std::cout, A) << std::endl;
    print(std::cout, B) << std::endl;
    print(std::cout, C) << std::endl;
    print(std::cout, D) << std::endl;
    return 0;
}
