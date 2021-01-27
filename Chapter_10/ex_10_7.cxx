#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::cin;
using std::vector;
using std::list;
using std::copy;
using std::fill_n;
using std::back_inserter;

int main(){

    //(a)
    vector<int> vec; list<int> lst; int i;
    while(cin >> i)
	lst.push_back(i);
    //copy(lst.cbegin(), lst.cend(), vec.begin()); 
    // in copy() function, vec needs to have enough space to hold elements in lst.
    // however, vec is empty
    // so we can either:
    // 1. resize the vec before using copy()
    // 2. use a back_inserter
    vec.resize(lst.size());
    copy(lst.cbegin(), lst.cend(), vec.begin()); 
   
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));

  
    //(b)
    vector<int> vec1;
    vec1.resize(10); // vec1.reserve(10);
    // reserve(n) only reserves enough space to hold (possibly more than) n elements
    //  it does not change the size of vector.
    //  after vec1.reserve(10), vec1 is still empty
    fill_n(vec1.begin(), 10, 0);     
}
