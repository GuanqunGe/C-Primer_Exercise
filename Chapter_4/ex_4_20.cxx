#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
int main(){

    vector<string> strings={"","Hello", "World"};
    auto iter = strings.begin();
    cout << iter++->empty() << endl;   //print out 1 --> true
    cout << iter->empty() << endl; // print out 0 --> false

    return 0;   
}
