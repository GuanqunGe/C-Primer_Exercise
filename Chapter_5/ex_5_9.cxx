#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

    char ch;
    //counter for vowels, and non-vowels
    // **remember to use unsigned!!!
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
  
    while(cin >> ch){
        if(ch == 'a') ++aCnt;
        else if(ch == 'e') ++eCnt;
        else if(ch == 'i') ++iCnt;
        else if(ch == 'o') ++oCnt;
        else if(ch == 'u') ++uCnt;
        else ++otherCnt;
    }

    cout << "a :" << aCnt << endl;
    cout << "e :" << eCnt << endl;
    cout << "i :" << iCnt << endl;
    cout << "o :" << oCnt << endl;
    cout << "u :" << uCnt << endl;
    cout << "other :" << otherCnt << endl;

    return 0;

}
