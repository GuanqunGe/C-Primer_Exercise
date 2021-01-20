#include <iostream>
#include <vector>

std::ostream &print(std::ostream &os, const std::vector<int> &vec){
    for(auto &e : vec)
	os << e << " ";
    return os;
}

void info(const std::vector<int> &vec){
    std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
}

int main(){

    std::vector<int> vec;
    info(vec);

    for(int i= 25; i >= 0; --i)
	vec.push_back(i);

    info(vec);
    print(std::cout, vec) << std::endl;

    vec.resize(50);
    info(vec);
    print(std::cout, vec) << std::endl;


    vec.reserve(75);
    info(vec);
    print(std::cout, vec) << std::endl;

    while(vec.size() != vec.capacity())
	vec.push_back(1);
    info(vec);
    print(std::cout, vec) << std::endl;

    return 0;
}
