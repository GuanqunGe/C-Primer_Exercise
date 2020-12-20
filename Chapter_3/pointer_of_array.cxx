//to find out what is in the pointer of array, what does it points to
#include <iostream>

using std::cout;
using std::endl;

int main(){

    int arr[] = {1, 2, 3, 4, 5}; // int array of 5
    int (*ptr)[5] = &arr;  //pointer to this array

    cout << arr << " " << *arr << endl;   //expect *arr to be 1
    cout << arr +1 << endl;   //int on my computer is 4 bytes

    cout << ptr << " " << *ptr << endl;   //ptr has the same value of arr, however, *ptr doesn't give the value of first eelement, instead it gives the address of array still. Since *ptr returns an array, which is essentially the address of the array's first element.

    cout << ptr+1 << " " << *(ptr+1) << endl;  //since ptr is a pointer that points to an array of 5 ints, so what ptr+1 does is to move ptr forward, by a step of (size of 5 ints), which is 20 bytes on my computer
    return 0;

}
