#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1&& v1, T2&& v2){
    //f(v2, v1);
    f(std::forward<T2>(v2), std::forward<T1>(v1));
}

void f1(int i, int j){
    std::cout << "f1(int i, int j): " <<  i+j << std::endl;
}

void f2(int &i, int j){

    std::cout << "f2(int &i, int j): " << i++ << " " << j << std::endl;
    std::cout << "f2(int &i, int j): " <<  i+j << std::endl;
}

void f3(int &&i, int j){
    std::cout << "f3(int &&i, int j): " << i+j << std::endl;
}

int main(){

    int i = 3, j = 5;

    flip(f1, i, j); //implicitly deduce template arguments
    std::cout << i << " " << j << std::endl;
    flip(f2, i, j);
    std::cout << i << " " << j << std::endl;
    flip(f3, i, 9);

    return 0;
}
