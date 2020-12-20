#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){

    vector<int> ints={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //print vector before the change
    for(auto iter = ints.cbegin(); iter != ints.cend(); iter++)
        cout << *iter  << " ";
    cout << endl;

    //change the values in the vector
    for(auto iter = ints.begin(); iter != ints.end(); iter++)
	// *iter *= *iter;   //power of 2
        *iter *= 2;
    
    //print vector after change
    for(auto iter = ints.cbegin(); iter != ints.cend(); iter++)
        cout << *iter  << " ";
    cout << endl;

    return 0;
}
