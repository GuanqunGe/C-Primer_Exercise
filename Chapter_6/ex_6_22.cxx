#include <iostream>

void swap_pointer(int *(&r1), int *(&r2)){   //to swap two pointers to point to each other's pointee, have to use reference. Otherwise it's only the copy of the arguments that will get swapped, not the argument themselves.
     auto temp_pointer = r1;
     r1 = r2;
     r2 = temp_pointer;
}

int main(){

    int i = 1, j = 2, *pi = &i, *pj = &j;
    std::cout << "pointer pi: " << pi << ", pointer pj: " << pj << std::endl;
    swap_pointer(pi, pj);
    std::cout << "pointer pi: " << pi << ", pointer pj: " << pj << std::endl;

    return 0;
}
