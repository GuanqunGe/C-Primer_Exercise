#include <iostream>
#include <typeinfo>

template <typename T> class Stack{
public:

    // see: https://stackoverflow.com/questions/21598635/how-is-a-template-instantiated
    typedef typename T::ThisDoesntExist MyType;

    //this is useless for debugging
    //Stack(){
    //	std::cout << typeid(T).name() << std::endl;
    //}
};

//void f1(Stack<char>){}	 // will require  instantiation of Stack<char>
//void f1(Stack<char>);	 	// no instantiation

class Exercise{
    Stack<double> &rsd;		// no instantiation
    Stack<int> si;              //instantiation of Stack<int> 
};

int main(){

    Stack<char> *sc;		//no instantiation
    f1(*sc);                    //instantiation of Stack<char>
    int iObj = sizeof(Stack<std::string>);  //instantiation of Stack<std::string>

    return 0;
}
