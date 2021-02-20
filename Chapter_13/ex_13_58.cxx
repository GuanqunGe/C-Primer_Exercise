#include <iostream>
#include <initializer_list>
#include <vector>
#include <algorithm>

class Foo{
public:
    Foo()=default;
    Foo(std::initializer_list<int> il):data(il){}

    //copy-control members will be synthesized by the compiler

    void push_back(int) &; //do not allow to run on rvalue object
    Foo sorted() &&;
    Foo sorted() const &;
    void print() const;
private:
    std::vector<int> data;
};

void Foo::push_back(int t) &{
    data.push_back(t);
}


Foo Foo::sorted() &&{
    std::cout << "Foo sorted() &&" << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}

//correct method 1
Foo Foo::sorted() const &{
    std::cout << "Foo sorted() const &" << std::endl;
    Foo ret(*this);
    std::sort(ret.data.begin(), ret.data.end());
    return ret;
}

/*
//correct method 2
Foo Foo::sorted() const &{
    std::cout << "Foo sorted() const &" << std::endl;
    return Foo(*this).sorted();
}
*/


//wrong method
//Function will run in endless loop.
//Running program with this definition cause segmentation fault.
/*
Foo Foo::sorted() const &{
    Foo ret(*this);
    return ret.sorted();
}
*/

void Foo::print() const {
    for(auto &i:data)
	std::cout << i << " ";
    std::cout << std::endl;
}


int main(){

    Foo f1 = {1, 9 ,8 ,3, 5, 7, 6};
    Foo f1_sorted = f1.sorted();
    f1_sorted.print();

    Foo f2_sorted = Foo({7, 8, 4, 3}).sorted();
    f2_sorted.print();

    return 0;
}

