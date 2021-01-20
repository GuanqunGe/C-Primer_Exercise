#include <vector>
#include <iostream>

int FindIndex(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n){
    int i = 0;
    while( (begin+i) != end){
	if( *(begin+i) == n) return i;
	++i;
    }
    return -1;
}

// deal with const_iterator
std::vector<int>::const_iterator FindIterator(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n){
    int i = FindIndex(begin, end, n);
    if(i == -1) return end;
    else return begin + i;
}

//deal with regular iterator
std::vector<int>::iterator FindIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end, int n){
    int i = FindIndex(begin, end, n);
    if(i == -1) return end;
    else return begin + i;
}

int main(){
    std::vector<int> vec;
    std::cout << "Please enter a list of numbers: ";
    for(int num; std::cin >> num; ) vec.push_back(num);

    int int_to_find;
    std::cout << "Please enter a number to find: ";
    std::cin.clear();  //restore the state of cin
    std::cin >> int_to_find;

    auto iter = FindIterator(vec.cbegin(), vec.cend(), int_to_find);
    //auto iter = FindIterator(vec.begin(), vec.end(), int_to_find);
    std::cout << int_to_find << " is in vector: " << (iter != vec.end() ? "true" : "false") << std::endl;  // vec.cend() == vec.end() is true.

    return 0;
}
