#include <iostream>

class Debug{
private:
    bool hw;
    bool io;
    bool other;
public:
    //all functions are defined inside the class--> implicitly inline
    // constructors can't be const, yet constexpr functions are const.. a bit conflicting
    constexpr Debug(bool b = true): hw(b), io(b), other(b){}  
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o){}
    constexpr bool any() {return hw || io || other; }  //constexpr functio members are implicitly const
    void set_io(bool b){io = b;}
    void set_hw(bool b) {hw = b;}
    void set_other(bool b) {other = b;}

};

int main(){
    constexpr Debug io_sub(false, true, false);
    if(io_sub.any()) std::cout << "error message io_sub" << std::endl;

    constexpr Debug prod = false;  //implicit conversion
    if(prod.any()) std::cout << "error message prod" << std::endl;
    //prod.set_io(false);// error: prod is a const object, yet 'this' in set_io is pointer to non-const object

    constexpr Debug gen;
    if(gen.any()) std::cout << "error message gen" << std::endl;

    Debug reco(false);
    if(reco.any()) std::cout << "error message reco 1" << std::endl;
    reco.set_hw(true);
    if(reco.any()) std::cout << "error message reco 2" << std::endl;

    return 0;
}
