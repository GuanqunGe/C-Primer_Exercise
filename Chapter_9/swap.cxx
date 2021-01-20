// explore what swap does to array, vector
// for array, swap simply exchanges the value of elements between two arrays
// for vector, swap seems to be only exchange the name of the vector, with one exception that, the address of vector (&vec) doesn't change after swap

#include <iostream>
#include <array>
#include <vector>

int main(){
   
    //------- first, on arrays --------
    std::array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7,8,9,10}, arr2{0,0,0,0,0,0,0,0,0,0};
    std::cout << "Array, Before swap" << std::endl;
    std::cout << "address of arr1: " << &arr1 << ", address of arr2: " << &arr2 << std::endl;
    std::cout << "address of arr1[1]: " << &arr1[1] << ", value: " << arr1[1] << std::endl;
    std::cout << "address of arr2[1]: " << &arr2[1] << ", value: " << arr2[1] << "\n" << std::endl;

    swap(arr1, arr2);
    
    std::cout << "Array, After swap" << std::endl;
    std::cout << "address of arr1: " << &arr1 << ", address of arr2: " << &arr2 << std::endl;
    std::cout << "address of arr1[1]: " << &arr1[1] << ", value: " << arr1[1] << std::endl;
    std::cout << "address of arr2[1]: " << &arr2[1] << ", value: " << arr2[1] << "\n" << std::endl;


    //---- second, on vector ------
    std::vector<int> vec1(10, 3), vec2{-1, -1, -1 , -1};
    int *p1 = &vec1[1], *p2 = &vec2[1];
    std::cout << "Vector, Before swap: " << std::endl;
    std::cout << "vec1 size: " << vec1.size() << ", vec2 size: " << vec2.size() << std::endl;
    std::cout << "address of vec1[1]" << &vec1[1] << ", p1: " << p1 << ", value: " << vec1[1] << std::endl;
    std::cout << "address of vec2[1]: " << &vec2[1] << ", p2: " << p2 << ", value: " << vec2[1] << std::endl;
    std::cout << "address of vec1: " << &vec1 << ", address of vec2: " << &vec2 << std::endl;
    std::cout << "first element through (*p)[0]: vec1: " << (*(&vec1))[0] << ", vec2: " << (*(&vec2))[0]<< std::endl;

    swap(vec1, vec2);

    std::cout << "Vector, After swap: " << std::endl;
    std::cout << "vec1 size: " << vec1.size() << ", vec2 size: " << vec2.size() << std::endl;
    std::cout << "address of vec1[1]" << &vec1[1] << ", p1: " << p1 << ", value: " << vec1[1] << std::endl;
    std::cout << "address of vec2[1]: " << &vec2[1] << ", p2: " << p2 << ", value: " << vec2[1] << std::endl;
    std::cout << "address of vec1: " << &vec1 << ", address of vec2: " << &vec2 << std::endl;
    std::cout << "first element through (*p)[0]: vec1: " << (*(&vec1))[0] << ", vec2: " << (*(&vec2))[0]<< std::endl;


    return 0;
}
