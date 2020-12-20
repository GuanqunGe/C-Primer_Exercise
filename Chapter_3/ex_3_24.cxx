#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){

    int element;
    vector<int> ints;
    cout << "Please enter a list of integer to proceed with" << endl;
    while(cin >> element) ints.push_back(element);

    if(ints.empty()){
        cout << "No data input?" << endl;
        return -1;
    }

    //print the adjacent sum
    if(ints.size() > 1) cout << "Adjacent sum is: " << endl;
    for(auto iter = ints.cbegin(); iter+1 != ints.cend(); iter++)
        cout << (*iter) + *(iter+1) << " ";
    cout << endl;

 
    //print ith and ith-to-last sum
    cout << "The ith and ith-to-last sum is: " << endl;
    auto beg_iter = ints.cbegin(), end_iter = ints.cend() -1;
    while(beg_iter <= end_iter){
        cout << *beg_iter + *end_iter << " ";
        beg_iter++;
        if(end_iter != ints.cbegin()) end_iter--;  //needs to be careful about this one, for 1-element case
    }
    cout << endl;

    return 0;
  
}
