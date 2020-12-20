#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){
   
    const vector<int> const_vec{1, 2, 3};
    const_vec.push_back(4);  //wrong, can't add new element to const vector
    const_vec[1] = 4;  //wrong, elements in const vectors are read-only

    
    // ::const_iterator can be moved around
    vector<int> vint{1, 2, 3, 4, 5};
    //for(auto iter = vint.cbegin(); iter!=vint.end(); iter++)   //both works
    for(auto iter = vint.cbegin(); iter!=vint.cend(); iter++)    //works
        cout << *iter << endl;

    return 0;
}
