#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){

    const string hexdigit = "0123456789ABCDEF";
    int number;  //decimal number, can't be larger than INT_MAX
    string out;   // the corresponding hex string

    cout << "Please enter a non-negative decimal number: " <<endl;
    cin >> number;
    if(number < 0){
        cout << "Negative number, quit.." << endl;
	return -1;
    }


    //calculate the hex string, now in 'out', it's reversed ordered.     
    int num_copy = number;
    while(num_copy > 0){
        decltype(hexdigit.size()) res = num_copy % 16;
	out += hexdigit[res];
 	num_copy /= 16;
    }
    out += '0';  // to take care of the number "0"


  
    //print out the hex string
    cout << "Corresponding hex number is : ";

    //be careful with the unsigned int.
    //for(auto i = out.size()-1; i >=0 ; i--) // wrong, as -1 would be coverted to a larger number
    for(auto i = out.size(); i >= 1 ; i--)
	cout << out[i-1];
    cout <<endl;

    return 0;
}
