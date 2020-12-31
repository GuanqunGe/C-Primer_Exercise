#include <iostream>
#include <vector>
#define NDEBUG   // or use g++ -DNDEBUG to define NDEBUG variable.

void Print(std::vector<int>::iterator begin, std::vector<int>::iterator end){

    #ifndef NDEBUG
    std::cout << __func__ << ": size of the vector on the call: " << end - begin << ", ";
    #endif
    if(begin == end){
	 return;
    }
    std::cout << *begin << std::endl;;
    Print(begin+1, end);
}

int main(){

    std::vector<int> ints={1, 2, 3, 4, 5, 6, 7, 8,9, 10};
    Print(ints.begin(), ints.end());
    return 0;
}
