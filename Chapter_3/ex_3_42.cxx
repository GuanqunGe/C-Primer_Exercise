#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){

    vector<int> ints={1, 2, 3, 4, 5};
    int int_array[10]={};
    
    for(decltype(ints.size()) i =0; i<ints.size(); i++)
	int_array[i] = ints[i];

    for(size_t i=0; i<10; i++)
	cout << int_array[i]<< " ";
    cout << endl;

    return 0;
}
