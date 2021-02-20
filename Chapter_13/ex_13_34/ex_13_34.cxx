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

    return 0;   
}
