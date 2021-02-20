#include <iostream>
#include <string>

class Employee{
public:
    inline Employee();
    inline Employee(const std::string &);

    //copy constructor
    Employee(const Employee&);

    //copy assignment operator
    inline Employee& operator=(const Employee& );

    const std::string& GetName() const {return ename; }
    unsigned GetID() const {return eid; }
private:
    std::string ename;
    unsigned eid;
    static unsigned ecounter;
};

Employee::Employee():eid(ecounter++){}

Employee::Employee(const std::string &s):ename(s), eid(ecounter++){}

unsigned Employee::ecounter = 1; //must define and initilaize non-const static data member outside the class body

Employee::Employee(const Employee &in): ename(in.ename), eid(ecounter++){}

Employee& Employee::operator=(const Employee &in){
    ename = in.ename;
    return *this;
}

int main(){

    Employee A;
    Employee B("Sarah");

    Employee C = B;

    A = B;
    std::cout << A.GetName() << ", " << A.GetID() << std::endl;

    // A = "Andy"; //no conversion from const char* to const Employee&
    		   // is implicit conversion only used in class construction?
    A = Employee("Andy");

    Employee D("Nancy");
    //Employee E = "Mark"; //wrong, no known conversion from const char* to non-scalar type Employee, don't understand why.

    std::cout << A.GetName() << ", " << A.GetID() << std::endl;
    std::cout << B.GetName() << ", " << B.GetID() << std::endl;
    std::cout << C.GetName() << ", " << C.GetID() << std::endl;
    std::cout << D.GetName() << ", " << D.GetID() << std::endl;
    //note that there is a gap between C.eid and D.eid, due to the temporary object used in copy assignment 'A=Employee("Andy")'
    return 0;
}

//Yes, because we need the employee identifier to be unique. Synthesized copy-control functions
//will simply copy/copy-assign each member of the class, which is clearly not what we want. 
