#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(){

    vector<string> text{"I am a student from XXX university,", "and I like baseball.",
			 "", "What about you?"};

    //print the text before changing it
    for(auto iter = text.cbegin(); iter != text.end(); iter++)
	cout << *iter << " ";
    cout << endl;

   
    //change the first paragraph to all uppercase
    //for(auto iter = text.begin(); iter!=text.end() && !(*iter).empty() ; iter++)  //works the same as line below
    //loop over to iterate through each string
    for(auto iter = text.begin(); iter!=text.end() && (!iter->empty()) ; iter++){
        //given an string (iterator of string), loop over its characters
 	for(auto element_iter = iter->begin(); element_iter != iter->end(); element_iter++)
	    *element_iter = toupper(*element_iter);
    }


    //print the updated text
    for(auto iter = text.cbegin(); iter != text.cend(); iter++)
	cout << *iter << " ";
    cout << endl;

    return 0;
}
