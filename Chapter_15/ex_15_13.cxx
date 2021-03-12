#include <iostream>
#include <string>

class base{
public:
    base(const std::string &s=""): basename(s) {}
    std::string name() {return basename; }
    virtual void print(std::ostream &os) {os << basename; }
    //this print function takes reference to std::ostream, and write value of basename to ostream
private:
    std::string basename;
};

class derived: public base{
public:
    derived(int num = 0, const std::string &s = ""): base(s), i(num){}

    //this print function takes a reference to std::ostream, and intends to write both members of 
    //its base class and members of its own into the ostream.
    void print(std::ostream &os){
	//print(os);  //wrong, will call this function recursively and result in endless recursion.
        this->base::print(os);
	os << " " << i;
    }
private:
    int i;
};

int main(){
    base b("Base");
    derived d(1, "Derived");
    b.print(std::cout);
    std::cout << std::endl;

    d.print(std::cout);
    std::cout << std::endl;


    return 0;
}
