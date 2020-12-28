#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

    string line;
    // counter for vowels, and special character (blank, tab, newline) counter
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt =0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
  
    char ch;
    // cin >> char omits whitespace characters
    // cin.get(char) reads next character, no matter what it is (until end-of-file)
    while( cin.get(ch)){
        switch(ch){
	    case 'a': case 'A':
		++aCnt;
		break;
	    case 'e': case 'E':
		++eCnt;
		break;
	    case 'i': case 'I':
		++iCnt;
		break;
	    case 'o': case 'O':
		++oCnt;
		break;
	    case 'u': case 'U':
		++uCnt;
		break;
	    case ' ':
		++spaceCnt;
		break;
	    case '\t':
		++tabCnt;
		break;
	    case '\n':
		++newlineCnt;
		break;
        }
    }


    /* ********************** The code below is not so good, it adds an \n to everyline it read ************ 
    while(getline(cin, line)){  //delimiter is \n, so the line doesn't have \n in it.
 
        //tranverse all the characters in line
	for(const auto &ch : line){
            switch(ch){
                case 'a':     //both 'a' and 'A' should be counted.
	        case 'A':
		    ++aCnt;
		    break;
	        case 'e': case 'E':
		    ++eCnt;
		    break;
	        case 'i': case 'I':
		    ++iCnt;
		    break;
	        case 'o': case 'O':
		    ++oCnt;
		    break;
	        case 'u': case 'U':
		    ++uCnt;
		    break;
                case ' ':
		    ++spaceCnt;
		    break;
		case '\t':
		    ++tabCnt;
		    break;
           }
       }

       ++newlineCnt; //after processing each line, add 1 to the newline \n counter.
    }
    **************************************************************************************/

    cout << "a/A: " << aCnt << endl;
    cout << "e/E: " << eCnt << endl;
    cout << "i/I: " << iCnt << endl;
    cout << "o/O: " << oCnt << endl;
    cout << "u/U: " << uCnt << endl;
    cout << "space: " << spaceCnt << endl;
    cout << "\\t: " << tabCnt << endl;
    cout << "\\n: " << newlineCnt << endl;
    return 0;
}
