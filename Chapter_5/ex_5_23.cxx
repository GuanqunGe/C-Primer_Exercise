#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;   //standard class

int main(){
    int val1=0, val2 = 0;

    //continously asking for numbers to add
    while(true){
        cout << "Please enter two integers to do the division " << endl;
        try{
	    if(cin >> val1 >> val2){
	        if(val2 ==0) throw runtime_error("Divisor may not be 0");
	        cout << val1<< "/" << val2 << "=" << val1/static_cast<double>(val2) << endl;
	    }
	    else throw runtime_error("Something wrong with reading numbers");
         }
         catch(runtime_error err){
             cout << err.what() << "\nTry again? Enter y or n: ";
             char c;
             //this bit doesn't really work when cin>> failed in the try block. how can I make cin to take input twice without one interfering with the other??
             if(!(cin >> c) || c=='n') break;
         }
    }

    return 0;
}
