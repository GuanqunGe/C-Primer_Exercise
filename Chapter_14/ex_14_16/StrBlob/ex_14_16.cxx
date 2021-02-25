#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "StrBlobPtrPtr.h"
#include "ConstStrBlobPtr.h"
#include <iostream>

int main(){

    StrBlob sb1;
    StrBlob sb2 = {"Hello", "Please", "Check", "Our", "New", "Book"};
    StrBlob sb3 = sb2;

    sb1.push_back("Today is pretty");
    sb1.push_back("Nice");
   

    std::cout << "sb2 == sb3 :"  << ( sb2 == sb3 ? "true": "false") << std::endl;
    std::cout << "sb1 != sb2: " << (sb1 != sb2 ? "true" : "false" ) << std::endl;
    std::cout << "sb1 < sb2: " << (sb1 < sb2 ? "true":"false" ) << std::endl;
    std::cout << "sb1 > sb2: " << (sb1 > sb2 ? "true" : "false" ) << std::endl;

    StrBlobPtr p1(sb1);
    StrBlobPtr p2(sb1, 1);
    std::cout << "p1 == p2: " << ( p1 == p2 ? "true" : "false" ) << std::endl;
    std::cout << "p1 < p2: " << ( p1 < p2 ? "true" : "false") << std::endl;
    std::cout << "p1 > p2: " << ( p1 > p2 ? "true" : "false") << std::endl;

    //p1.incr();
    ++p1;
    std::cout << p1.deref() << std::endl;
    std::cout << *p1 << " " << p1->size() <<  std::endl;
    std::cout << (p1--).deref() << std::endl;
    std::cout << p1.deref() << std::endl;
    std::cout << "p1 == p2: " << ( p1 == p2 ? "true" : "false" ) << std::endl;
    std::cout << "p1 != p2: " << ( p1 != p2 ? "true" : "false" ) << std::endl;
    
    StrBlobPtr p3(sb2);
    std::cout << "p3 < p1: " << ( p3 < p1 ? "true" : "false" ) << std::endl;
    std::cout << "p3 > p1: " << ( p3 > p1 ? "true" : "false") << std::endl;
    std::cout << "p3 >= p1: " << ( p3 >= p1 ? "true" : "false") << std::endl;
    std::cout << "p3 == p1: " << (p3 == p1 ? "true" : "false") << std::endl;
    std::cout << (p3 + 2).deref() << ": Check" << std::endl;
    std::cout << (p3 + 4 - 1).deref() << ": Our" << std::endl;

    const StrBlob sb4({"Hey", "Babe"});
    std::cout << "sb1 != sb4: " << (sb1 != sb4 ? "true" : "false" ) << std::endl;
    std::cout << sb2[0] << " " << sb4[0] << std::endl;
    sb2[0] = "Hi";
    std::cout << sb2[0] << " " << sb4[0] << std::endl;

    ConstStrBlobPtr sp1(sb4);
    std::cout << *sp1 << std::endl;
    std::cout << sp1->size() << std::endl;

    StrBlobPtrPtr pp1(p1);
    std::cout << p1->size() << std::endl;
    //std::cout << pp1->size() << " " << p1->size() << std::endl;
    //since StrBlobPtr does not have size() member, so we can't do pp1->size()
    //pp1->operator->()->size()  is the same as (pp1.operator->())->operator->()->size() 
    std::cout << pp1->operator->()->size() << std::endl;
    std::cout << pp1->deref() << std::endl;

    pp1->incr();
    std::cout << p1->size() << std::endl;
    std::cout << pp1->deref() << std::endl;
    return 0;
}
