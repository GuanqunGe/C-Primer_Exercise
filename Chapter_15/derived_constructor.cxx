// the purpose of this code is just to see how the derived class inherits private constructors
#include <iostream>
#include <string>

class Student{
public:
    Student() = default;
    Student(const std::string &s, int pid):Student(pid){
	name = s;
    	std::cout << "Student::Student(const std::string&, int)" << std::endl;
    }

private:
//protected:
    Student(int pid): ID(pid){
	std::cout << "Student::Student( int)" << std::endl; }
    std::string name;
    int ID;
};

class Dorm : public Student{
public:
    using Student::Student;
    Dorm(const std::string& s, int pid, int d):Student(s, pid), dorm(d){}
private:
    int dorm = 0;
};

int main(){

    Dorm d("Sun yue", 40);
    Dorm d1(40); //note that this will cause compilation error
		 // "‘Dorm::Dorm(int)’ is implicitly deleted because the default definition would be ill-formed"
		 // reason is as follows:  using declaration will generate two derived constructor: 
		 // 1. Dorm(const std::string &s, int pid): Student(s, pid){}
		 // 2. Dorm(int) : Student(int) {}
		 // not that the second function uses Student(int) function, however, this function is private member of Student
		 // so Dorm class does not have access to it, thus Dorm(int) will be an deleted function (and it's private).
		 //
		 // If we define the Student::Student(int) as a protected member, then Dorm(int):Student(int){} will be a valid 
		 // constructor for Dorm, but note that this Dorm(int) constructor will be a protected member of Dorm, so can't be used
		 // by user code either.
    return 0;
}
