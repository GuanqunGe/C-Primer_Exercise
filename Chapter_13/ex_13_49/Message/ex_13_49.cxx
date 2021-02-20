// test the implemented Folder and Message class
#include "Folder.h"
#include "Message.h"
#include <iostream>

int main(){

    Message A("Hey, this is Daniel");
    Message B("Hey, how are you?");
    Message C("Hello");
    
    Folder F1("Greeting");
    { Folder F2("business");}
    A.save(F1); B.save(F1); C.save(F1);

    {
	Message D("Do you intent to sale your house");
	D.save(F1);
    std::cout << &A << " " << &B << " " << &C << " " << &D << std::endl;
    }
 
    swap(A, B);
    //C.remove(F1);
    std::cout << &A << " " << &B << " " << &C << std::endl;

    //test move constructor and move assignment
    Message D(std::move(A));
    std::cout << A.Content() << " " << D.Content() << std::endl;

    A = std::move(B);
    std::cout << A.Content() << " " << B.Content() << std::endl;

    Folder F2 = std::move(F1);

    F1 = std::move(F2);
    return 0;   
}
