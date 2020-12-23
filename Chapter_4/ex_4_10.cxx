#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

    int value=0;
    cout << "Enter integers"<< endl;
    // method 1
    while(cin >> value && value !=42){  //terminate when cin reads an end-of-file 
     //   cout << value << endl;
    }

    //method 2
    while(value != 42){   // will not terminate unless cin reads an value of 42
	 cin >> value;  
    }
    return 0;
} 
