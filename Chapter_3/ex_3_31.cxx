#include <iostream>
using std::cout;
using std::endl;

int main(){

    int ints[10]={}; //list initialize it, so all the elements are 0

    //two different ways to give element of array values
    //first one
    int index =0;
    for(auto &i : ints){
        i = index;
 	index++;
    }

    //second one
    for(unsigned i =0; i< 10 ; i++) ints[i] = i;

    for(const auto &i : ints) cout << i << " ";
    cout << endl;
    return 0;
}
