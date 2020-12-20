#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){

    string s = "She is a beauty!";

    for(auto &c : s){
    //for(char &c : s){
        c = 'X';
        cout << s << endl;
    }

    return 0;
}
