// If vi is a vector, string, deque, or list container
// the loop is essentially same as:
// 	while( iter != vi.end()){
//     	     if( *iter % 2) iter = vi.insert(iter, *iter);
// 	}
// 	++iter;
// So three cases:
// 1. if vi is empty, while loop will not run, later use of iter will yield undefined behavior.
// 2. if vi is not empty, and its first element is odd-valued, the loop will not exit, and will keep adding duplicate value to the beginning of the container.
// 3. if vi is not empty and its first element is even-valued, the loop will not exit due to the fact that iter is never updated.


#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec{2, 2, 3, 4, 5, 6};
    //std::vector<int> vec;

    auto iter = vec.begin();
    while( iter != vec.end())
	if( *iter % 2)
	    iter = vec.insert(iter, *iter);
        ++iter;

    return 0;
    
}
