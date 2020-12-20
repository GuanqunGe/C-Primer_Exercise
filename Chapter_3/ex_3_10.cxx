#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

int main(){

    string s;
    cout << "Please enter a string to proceed with" << endl;

    if(getline(cin, s)){
        for(auto c : s){
            if(!ispunct(c)) cout << c;
        }
        cout << endl;
        return 0;
    }else{
        cerr << "Fail to read string" << endl;
        return -1;
    }
}
