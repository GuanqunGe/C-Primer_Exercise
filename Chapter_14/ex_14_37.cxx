#include <iostream>
#include <vector>
#include <algorithm>

struct Equal{
    bool operator()(int arg1, int arg2) const{
	return arg1 == arg2;
    }
};

struct UEqual{
    UEqual(int n) : val(n){}
    bool operator()(int arg) const { return arg == val; }
private:
    int val;
};

void print_vec(const std::vector<int> &vec){
    for(auto iter = vec.begin(); iter != vec.end(); )
	std::cout << *iter++ << " " ;
    std::cout << std::endl;
}

int main(){
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,1,6,3,5,8,3,2,6};
    
    //print vec before
    std::cout << "Before replacing: ";
    print_vec(vec);

    int old_val, new_val;  //numbers to replace/be replaced
    std::cout << "Numbers wish to replace: ";
    std::cin >> old_val >> new_val;

    //replace certain number
    //-method 1
    //I thought about std::replace but obviously that doens't work
    Equal eq;
    //std::for_each(vec.begin(), vec.end(), [&old_val, &new_val, &eq](int &n)
    //		  { eq(n, old_val) ? n = new_val : n ; });

    //-method 2
    //std::replace_if could work, and to use that, will need to define a unary predicate
    std::replace_if(vec.begin(), vec.end(), UEqual(old_val), new_val);
 
    std::cout << "After replacing: ";
    print_vec(vec);

    return 0;
}
