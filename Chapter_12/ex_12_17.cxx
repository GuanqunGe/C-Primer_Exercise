#include <iostream>
#include <memory>

int main(){

    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;

    //(a), illgal, can't initialize a pointer with an int type
    //IntP po(ix);

    //(b) since the compiler don't know which memory is local or dynamic, I don't think this will
    //cause compilation error, but p1 will use default delete function to free the memory if necessary,
    //which is undefined on pointers to local memory 
    // -> indeed didn't have compilation error
    //IntP p1(pi);
    //std::cout << "p1: " << p1.get() << ", points to: " << *p1 << std::endl;
    //p1 = nullptr; //this line causes error  "free(): invalid pointer: 0x00007ffc7a474c9c"
		  // 0x00007ffc7a474c9c is the address of ix, also p1.get() 
    //std::cout << "Successfully freed the memory" << std::endl;

  
    //(c), correct, use pointer that points to dynamic memory to initialize p2
    IntP p2(pi2);
    std::cout << "p2: " << p2.get() << ", points to: " << *p2 << std::endl;
    //p2 = nullptr;  //needs to use with care, since pi2 still points to the same memory


    //(d), same problem as case (b)
    IntP p3(&ix);
    

    //(e) legal, construct an int object with value 2048 in the dynamic memory, and initialize p4 to 
    //point to the object
    IntP p4(new int(2048));


    //(f) I think it's legal, but since p5 is initialized using p2.get(), it will point to the same 
    //memory as p2, but neither of p5 and p2 know the existence of each other, they are independent.
    // destroying these two pointers will result in freeing the same memory twice, which is wrong
    IntP p5(p2.get());
    std::cout << "p5: "<< p5.get() << ", points to: " << *p5 << std::endl;
    p5 = nullptr; //essentially delete the object p5, p2 and pi2 all point to
    std::cout << "p2: " << p2.get() << ", points to: " << *p2 << std::endl;
    p2 = nullptr; //this will cause error: " double free or corruption (fasttop): 0xxxx memory address"


    return 0;
}
