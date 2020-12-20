#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

// to explore different ways to print the size and contents of the vector;

int main(){

    vector<string> s1{10, "hi"}, s2{"hi", "how", "are", "you"};
    vector<int> i1(10, 7), i2{7, 13};

    cout << "size of s1: " << s1.size() << endl;
    for(const auto &s: s1) cout << s << " ";
    cout << endl;


    cout << "size of s2: " << s2.size() << endl;
    for(decltype(s2.size()) i = 0; i != s2.size(); i++)
	cout << s2[i] << " ";
    cout << endl;

    cout << "size of i1: " << i1.size() << ", size of i2: " << i2.size() << endl;

    return 0;
}
