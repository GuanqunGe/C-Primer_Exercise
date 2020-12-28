#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

    char ch;
    // counter for vowels, and non-vowels
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt =0, uCnt = 0, otherCnt = 0;
   
    while(cin >> ch){
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
	    default:
		++otherCnt;
		break;
        }
    }


    cout << "a/A: " << aCnt << endl;
    cout << "e/E: " << eCnt << endl;
    cout << "i/I: " << iCnt << endl;
    cout << "o/O: " << oCnt << endl;
    cout << "u/U: " << uCnt << endl;
    cout << "other: " << otherCnt << endl;

    return 0;
}
