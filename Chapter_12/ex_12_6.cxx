#include <iostream>
#include <vector>

std::vector<int> *CreateVec(){

    return new std::vector<int>; //return pointer to an empty vector
}

void FillVec(std::istream &is, std::vector<int> &vec){
    for(int i; is >> i; )
	vec.push_back(i);
}

std::ostream &PrintVec(std::ostream &os, const std::vector<int> &vec){
    for(auto &e : vec)
	os << e << " ";
    return os;
}

int main(){

    std::vector<int> *p = CreateVec();
    FillVec(std::cin, *p);
    PrintVec(std::cout, *p) << std::endl;

    delete p; //do not forget to free the memory..

    return 0;
}
