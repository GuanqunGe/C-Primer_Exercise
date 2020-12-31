#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned Abs(int val){
    if(val < 0) return -1*val;   //it's fine, because this expresssion is guaranteed to be positive. 
    else return val;

    //OMG I found a genious solution online : return i >=0 ? i :-i;
}

int main(){

    int input;
    cout << "Please enter a number: ";
    cin >> input;
    cout << "The absolute value of " << input << " is " << Abs(input) << endl;
    return 0;
}
