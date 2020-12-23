#include <iostream>
using std::cout;
using std::endl;

int main(){
    
    const char *cp = "Hello World!";
    cout << *cp << *(cp+1) <<  endl;

    return 0;
}
