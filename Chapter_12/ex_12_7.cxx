#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> CreateVec(){
    return std::make_shared<std::vector<int>>();
}

void FillVec(std::istream &is, std::vector<int> &vec){
    for(int i; is >> i; )
	vec.push_back(i);
}

std::ostream &PrintVec( std::ostream &os, const std::vector<int> &vec){
    for( auto &e : vec)
	os << e << " ";
    return os;
}

int main(){

    {
	std::shared_ptr<std::vector<int>> ptr = CreateVec();
    	FillVec(std::cin, *ptr);
	PrintVec(std::cout, *ptr) << std::endl;
    }//ptr is out of scope, dynamic memory freed

    return 0;
}
