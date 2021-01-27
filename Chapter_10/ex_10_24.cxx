#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool check_size(const std::string &s, int sz){
    // use cast in case sz is negative
    return static_cast<int>(s.size()) < sz;
}

void find_int(const std::vector<int> &vec, const std::string &s){

    auto iter = std::find_if(vec.begin(), vec.end(), std::bind(check_size, ref(s), std::placeholders::_1) );
    //auto iter = std::find_if(vec.begin(), vec.end(), std::bind(check_size, s, std::placeholders::_1) );

    std::cout << "The first int that has value greater than " << s.size() << " is " << *iter << ", at index " << iter - vec.begin() << std::endl;
}

int main(){

    std::vector<int> ints = {-1, 1, -5, 2, 3, 4, 5, 6, 7};
    find_int(ints, "Hello");

    find_int(ints, "Hey");
    
    return 0;
}
