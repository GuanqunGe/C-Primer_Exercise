#include <iostream>
#include <iterator>  //to use begin, end function


using std::cout;
using std::endl;
using std::begin;
using std::end;

int main(){

    int a[]={1, 2, 3, 4, 5, 6}; //array of ints, 6 elements

    for(auto p = begin(a); p < end(a); p++)
        *p = 0;

    for(auto p = a; p != end(a); p++)
        cout << *p << " " ;
    cout << endl;

    return 0;
}
