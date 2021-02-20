#include <iostream>
#include <string>

class Employee{
public:
    inline Employee();
    inline Employee(const std::string &);

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

int main(){

    Employee A;
    Employee B("Sarah");

    std::cout << A.GetName() << ", " << A.GetID() << std::endl;
    std::cout << B.GetName() << ", " << B.GetID() << std::endl;

    return 0;
}
