#include <iostream>

int main(){

    int v = 10;

    // attention: the exercise requires that the lambda return a bool that indicates whether the CAPTURED value is 0
    auto f = [&v]{return v>0 ? --v, false : true; };
    //auto f = [&v]{return v == 0 ? true: ( --v, false) ; };  // caveat: will fall into endless loop if v is negative

    while(!f())
        std::cout << "v: " << v << std::endl;

    return 0;
}
