#include <iostream>
#include <vector>
#include <string>

template <class T>
void print(const T &t){
    //use subscript operator, requires that class T has subscript operator defined
    for(typename T::size_type i = 0 ; i != t.size(); ++i)
	std::cout << t[i] << " ";
    std::cout << std::endl;
}

int main(){
 
    print(std::vector<int>({1,2,3,4,5}));
    std::cout << "=========== " << std::endl;
    print(std::string("Hello"));

    return 0;
}
