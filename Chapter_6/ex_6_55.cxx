#include <iostream>
#include <vector>

typedef int Func(int, int);  //Func is an alias for function type
typedef int (*FuncP)(int, int);  //FuncP is an alias for function pointer type


//define add, subtract, multiply, and divide functions
int add(int val1, int val2){
    std::cout << "Addition of " << val1 << "+"<< val2 << "=";
    return val1+val2;
}

int subtract(int val1, int val2){
    std::cout << "Subtraction of " << val1 << "-"<< val2 << "=";
    return val1- val2;
}

int multiply(int val1, int val2){
    std::cout << "Multiplication of " << val1 << "*"<< val2 << "=";
    return val1*val2;
}

int divide(int val1, int val2){
    std::cout << "Integer division of " << val1 << "/"<< val2 << "=";
    return val1/val2;
}


//start of the main program
int main(){
    //define and initialize all these function pointers
    decltype(add)* p1 = nullptr;
    auto p2 = &add;
    int (*p3)(int, int) = subtract;
    FuncP p4 = multiply;
    Func *p5 = &divide;

    //put these pointers into a vector
    //std::vector<FuncP> vec = {p1, p2, p3, p4, p5};
    std::vector<FuncP> vec = {p1, add, subtract, multiply, divide};  //OK, "when we use the name of a function as a value, the function is automatically converted to a pointer."

    //loop over each pointer
    for(auto p : vec){

        //print out the pointer, which suprisingly give 1, for all the valid pointers.
	std::cout << p << std::endl;


        //if p is a valid pointer, perform the operation funtion to which it points supports
        if(p){
	    std::cout << p(1, 3) << std::endl;
	}
    }
   
    return 0;
}
