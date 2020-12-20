#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main(){

    int int_array[]={1, 2, 3, 4, 5};
    //int int_array[]={1, 2, , 3, 4, 5};  //wrong, can't initialize an arrray with one empty elemnt like this
    vector<int> ints(begin(int_array), end(int_array));

    cout << "size of vector: " << ints.size() << endl;
    for(const auto &e : ints)
  	cout << e << " ";
    cout <<endl;

    return 0;
}
