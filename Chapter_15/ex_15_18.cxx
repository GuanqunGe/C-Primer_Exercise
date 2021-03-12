#include <iostream>

class Base{
public:
    void pub_mem() { std::cout << "Base::pub_mem()" << std::endl; }

    virtual void memfcn(Base &b) {b = *this; } //legal, as this and b are the same type
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base{
    int f() {return prot_mem; }
    void memfcn(Base &b) override { b = *this; } //legal, as derived-to-base conversion exists
};

struct Priv_Derv : private Base{
    int f1() const {return prot_mem; }
    void memfcn(Base &b) override { b = *this; } //as derived class can alway access the public and protected member of its direct base
						 
};

struct Prot_Derv : protected Base{
    int f2() const {return prot_mem; }
    void memfcn(Base &b) override { b = *this; } //legal, as members and friends of derived class can alway access the public and 
						 // protected member of its direct base 
};

struct Derived_from_Public : public Pub_Derv{
    int use_base() {return prot_mem; }
    void memfcn(Base &b) override { b = *this; } //legal, as Derived_from_Public has access to the public member of Pub_Derv
};

struct Derived_from_Private : public Priv_Derv{
    //void memfcn(Base &b) override { b = *this; } //illegal, Derived_from_Private has no access to the private member of Priv_Derv
};

struct Derived_from_Protected : public Prot_Derv{
     int use_base() { return prot_mem; }
     void memfcn(Base &b) override { b = *this; } //legal, memebers/friends of Derived_from_Private has access to the protected member of Prot_Derv
};

int main(){
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1; //legal, b/c public members Pub_Derv class inherits from Base class are accesible to users of Pub_Derv class
    //p = &d2; // illgal, as Priv_Derv has private inheritance from Base class, members it inherits from Base class will be private members
	     // of Priv_Derv class, thus inaccessible to users of Priv_Derv class
	     
    //p = &d3; // illgal, as Prot_Derv has protected inheritance from Base class, members it inherits from Base class will be protected members
	     // of Prot_Derv class, so users of this class do not have access to these members, but derived class of Prot_Derv have access
	     // to them.

    p = &dd1; //legal, b/c Pub_Derv class has a public inheritance from Base class, so public members of Base class are also public members
	      // of Pub_Derv class, so as a derived class from Pub_Derv class with public inheritance, public members of Pub_Derv class are
	      // also public members of Derived_from_Public class, thus accessible by users of Derived_from_Public class

    //p = &dd2; //illegal, b/c members Priv_Derv inherits from Base class are now private members of Priv_Derv, Derived_from_Private class
  	      // does not have access to these members, let along it being the public interface of Derived_from_Private class.

    //p = &dd3; //illegal, b/c members Prot_Derv inherits from Base class are protected members of Prot_Derv class, members and friends of 
	      // Derived_from_Protected class has access to them. But as they remain protected members, users of Derived_from_Protected 
	      // don't have access to these members. 
    return 0;
}
