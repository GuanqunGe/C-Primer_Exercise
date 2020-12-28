#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
 
    string line;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

    cout << "Please enter text to proceed with.." << endl;
    
    while(getline(cin, line)){  //read in line, instread of character by character, to avoid "f f" being counted as "ff".
	char last_ch = ' ';   //for every line, reset the last character
	for(const auto & ch : line){
	    switch(ch){
		case 'f':
		    if(last_ch == 'f') ++ffCnt;
		    break;
		case 'l':
		    if(last_ch =='f') ++flCnt;
		    break;
		case 'i':
		    if(last_ch == 'f') ++fiCnt;
		    break;
            }
	    last_ch = ch;  //for each character read, update the last_character variable.
        }
    }

    /* ******************* Not good enough, this code ignores the spaces ***************
    char ch;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0; 
    char last_ch = ' ';
    while( cin >> ch){   // if replaced with cin.get(ch), this would work perfectly
        switch(ch){
	    case 'f':
		if(last_ch == 'f') ++ffCnt;
		break;
	    case 'l':
		if(last_ch == 'f') ++flCnt;
		break;
	    case 'i':
		if(last_ch == 'f') ++fiCnt;
		break;

        }
	last_ch = ch;
    }
    ***************************************************************************************/

    cout << "ff: " << ffCnt << endl;
    cout << "fl: " << flCnt << endl;
    cout << "fi: " << fiCnt << endl;

    return 0;
}
