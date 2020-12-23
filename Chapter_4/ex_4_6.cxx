#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){

    int value;
    cout << "Please enter an integer value to proceed" << endl;
    if(cin >> value){
        if(value %2 ==0) cout << value << " is an even number" << endl;
        else cout << value << " is an odd number" << endl;
        return 0;
    }else{
        cout << "No input?" << endl;
        return -1;
    }
}
