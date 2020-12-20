#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;
using std::endl;

int main(){

    unsigned grade; //grade can't be negative
    vector<unsigned> scores(11, 0);   //count can't be negative
    cout << "Please enter grades to proceed with" << endl;
  
    //given grade, increment corresponding elemenet in the vector
    auto iter = scores.begin();
    while(cin >> grade){
        //need to make sure grade is smaller than 100
        if(grade <= 100) (*(iter+grade/10))++;   //parenthesis needed
    }

    //print out the count
    for(auto citer = scores.cbegin(); citer != scores.cend(); citer++)
        cout << *citer << " ";
    cout << endl;

    return 0;
}
