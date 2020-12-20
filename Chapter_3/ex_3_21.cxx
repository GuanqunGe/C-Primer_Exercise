#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(){

    //vector<int> v{10, 42};
    //vector<int> v(10, 42);
    vector<string> v{10, "hello"};
    cout << "The size of v is: " << v.cend() - v.cbegin() << endl; 

    for(auto iter = v.cbegin(); iter != v.cend(); iter++)
	cout << *iter << endl;


    return 0;

}
