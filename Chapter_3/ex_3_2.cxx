#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(){

    string line;
    while(cin >> line){    //get one word at a time, whitespace as delimiter
   // while(getline(cin, line)){   //get one line at a time, '\n' is delimiter
	cout << line << std::endl;
    }

    return 0;
}
