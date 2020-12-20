#include <iostream>
using std::cout;
using std::endl;

int main(){

    int ints[10]={}; //list initialize it, so all the elements are 0
    int copy[10];  //undefined values

    int index =0;
    for(auto &i : ints){
        i = index;
 	index++;
    }

    for(unsigned i = 0; i< 10; i++) copy[i] = ints[i];

    for(const auto &i : copy) cout << i << " ";
    cout << endl;
    return 0;
}
