#include <iostream>
using std::cout;
using std::endl;

unsigned Counter(){

    static unsigned counter = 0;
    return counter++;
}

int main(){
    for(int i = 0; i< 10; ++i)
        cout << Counter() << " ";

    return 0;
}
