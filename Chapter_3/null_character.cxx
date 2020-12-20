#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(){

    string s = "hello!";
    cout << "size of s: " << s.size() << endl;

    char hello[6] = {'h', 'e','l','l','o','!'}; 
    char greeting[] = "hello!"; 
    //char greeting[6] = "hello!";  //wrong, should have size 7

    cout << hello;   //print char arrays without null character '\0' may lead to very weird results: http://www.cplusplus.com/forum/beginner/7947/
    cout << greeting << endl;
    return 0;
}
