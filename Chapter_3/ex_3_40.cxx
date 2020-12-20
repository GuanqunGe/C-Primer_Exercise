#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main(){

    const char ca1[]="Hello", ca2[]= "World!";
    char sum[255];

    cout << strcpy(sum, ca1) << endl;  //strcpy modifies sum, and returns sum

    //length of sum is now 5, but the size of sum is still 255
    cout << "length of sum is: " << strlen(sum) << endl;  
    cout << strcat(sum, ca2) << endl;   //strcat modifies sum and returns sum too
    cout << sum << endl;

    return 0;
}
