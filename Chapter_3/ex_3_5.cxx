#include <iostream> 
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

    string sum, current;
    while(cin >> current){
        sum += current + " ";
    }

    cout << "Sum of string is " << sum << endl;

    return 0;
}
