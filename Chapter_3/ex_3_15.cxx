#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(){

    string element;   //empty string
    vector<string> strings;   //empty vector

    cout << "Please enter a list of strings" << endl;

    //here, everything you type in is read as strings, include int, double, char.
    while(cin >> element) strings.push_back(element);

    for(const auto &e : strings) cout << e << " ";
    cout << endl;

    return 0;
}
