#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){

    do{
        cout << "Please enter two strings to compare: ";
	string str1, str2;
	if(cin >> str1 >> str2)
            cout << "'" << (str1 < str2 ? str1 : str2) << "' is less than/equal to '" << (str1 >= str2 ? str1 : str2) << "'\n" << endl;   //better place this inside the if(cin>>str) statement, otherwise even if the cin fails, this cout statement will still be executed. 
    }while (cin);   //whether the loop will continue relys on the status of cin.

    return 0;
}
