#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

int main(){

    int element;
    vector<int> ints;

    cout << "Please enter a list of integers to proceed with" << endl;
    while(cin >> element) ints.push_back(element);


    if(ints.empty()){
	cerr << "Nothing to process" << endl;
 	return -1;
    }

    //print the sum of each pair of adjacent elements
    cout << "The sum of adjacent elements: " << endl;
    for(decltype(ints.size()) i =0; i+1 != ints.size(); i++)
	cout << ints[i] + ints[i+1] << " ";
    cout << endl;


    //print the sum of the first and last, and the second and second-to-last
    cout << "The sum of ith and ith-to-last elements: " << endl;
    for(decltype(ints.size()) i =0; i < (ints.size() +1)/2; i++)
        cout << ints[i] + ints[ints.size()-1 -i] << " ";
    cout << endl;

    return 0;

}
