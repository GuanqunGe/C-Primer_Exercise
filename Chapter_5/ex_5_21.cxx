#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){

    bool found_duplicate = false;
    string curr_str, pre_str;   //stores current string, and previous string that starts with an uppercase letter.

    cout << "Please enter a list of strings/text.. " << endl;
    while(cin >> curr_str && !curr_str.empty()){
	if(!isupper(curr_str[0])){
	     pre_str = curr_str;
	     continue;
        }

	//code below only executes if the current string starts with an uppercase letter
	
	if(curr_str == pre_str){
	    found_duplicate = true;
	    break;
	}
        
        pre_str = curr_str;
    }

   if(found_duplicate) cout << "'" << curr_str << "' has appeared twice" << endl;
   else cout << "No words with uppercase letter are repeated" << endl;

   return 0;
}
