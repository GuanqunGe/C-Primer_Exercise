#include <vector>
#include <iostream>

bool FoundValue(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n){
   //begin is a const_iterator only means it cannot change the value it points to. begin itself can still change.
    while(begin != end){
	if(*begin == n) return true;
	++begin;
    }
    return false;
}

int main(){
    std::vector<int> vec;
    std::cout << "Please enter a list of numbers: ";
    for(int num; std::cin >> num; ) vec.push_back(num);

    int int_to_find;
    std::cout << "Please enter a number to find: ";
    std::cin.clear();  //restore the state of cin
    std::cin >> int_to_find;

    std::cout << int_to_find << " is in vector: " << (FoundValue(vec.begin(), vec.end(), int_to_find) ? "true" : "false") << std::endl;

    return 0;
}
