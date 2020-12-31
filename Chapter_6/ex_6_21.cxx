#include <iostream>

int GetLarger(const int &val, const int *p){
    return (val > *p) ? val:*p;
}

int main(){

    int i = 2, j = 3;
    std::cout << GetLarger(i, &j) << std::endl;
    return 0;
}
