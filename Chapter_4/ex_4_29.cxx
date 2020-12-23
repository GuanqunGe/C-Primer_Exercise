#include <iostream>

using std::cout;
using std::endl;

int main(){

    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;  //expect 10
    cout <<sizeof(p)/sizeof(*p) << endl;  //expect 2


    int (*p_array)[10] = &x;     //p_array is a pointer for an array of 10 ints
    cout << p_array << " " << p_array+1 << endl;//p_array moves with a step of 40 bytes (10 ints)
    cout << sizeof(p_array)<< endl;   //however, the size of p_array is not 40, instead it's 8, same as the pointer to int.
    return 0;
}
