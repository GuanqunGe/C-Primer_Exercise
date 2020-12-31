#include <iostream>
#include <vector>

void Print(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    
    if(begin == end){  //if reach off-the-end, terminates
        std::cout << std::endl;
        return ;
    }
    std::cout << *begin << " ";
    Print(begin+1, end);
}

int main(){

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    Print(vec.begin(), vec.end());
    return 0;
}
