#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(){

    string element;
    vector<string> strings; 

    cout << "Please enter a list of strings" << endl;
    while(cin >> element) strings.push_back(element);

    //change each string to uppercase
    for(auto &e : strings){ // access every string
 	for(auto &c: e){    //access every char in the string
            c = toupper(c);  // toupper only works on letters
 	}
    }

    //to print all the element in 1 line
    for(const auto &e : strings) cout << e << " ";
    cout << endl;

    //to print 8 elements in 1 line
    for(decltype(strings.size()) i =0; i != strings.size(); i++){
 	cout << strings[i] << " ";
	if((i+1)%8 == 0) cout << endl;   //to avoid printing newline for the 0th element
    }
    cout << endl;

    return 0;
}
