#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){

    vector<int> v1{1, 3, 5, 2, 6}, v2(10, 3);
    cout << "size of v1 is: " << v1.size() << ", size of v2: " << v2.size() <<endl;

    v1 = v2;  //replace v1 with what's in v2
    cout << "size of v1 is: " << v1.size() << ", size of v2: " << v2.size() <<endl;

    return 0;
}
