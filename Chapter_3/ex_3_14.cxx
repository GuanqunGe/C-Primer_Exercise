#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;
using std::endl;

int main(){
   
    int element;
    vector<int> ints;
    cout << "Please enter a list of integers"<< std::endl;

    //here if i give floating numbers, the decimal point will be treated as the end-of-filesymbol, so only the part before decimal point will be read.
    while(cin >> element) ints.push_back(element);

    for(auto e:ints) cout << e << " " ;
    cout << endl;

    return 0;
}
