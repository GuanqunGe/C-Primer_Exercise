#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

int main(){

    string current_str, last_str;
  
    cout << "Please enter the text: ";
    if(cin >> last_str){  //read the first word and save it to last string

	while(cin >> current_str){
	    if(current_str == last_str)	break;
	    last_str = current_str;
	}

	//cout << current_str << " " << last_str << endl;

        //when the while loop ends, last string always has the same value as current string, 
        //so the only thing I can use is the status of cin>> 
	// could use a boolean variable to indicate if strings have been repeated, to be safe.
	if(cin) cout << "'" << current_str << "' has appeared twice" << endl;
	else cout << "no word was repeated" << endl;
	return 0;
    }else{
 	cerr << "No input? " << endl;
	return -1;
    }
}
