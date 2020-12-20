// similar function as of ex_3_36_array.cxx to compare two vectors
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;


int main(){

    int size_a, size_b;  //size of vector a and b
    vector<int> a, b;
    
    //fill vector a 
    cout << "Enter the size of the 'a' vector you like to use: " << endl;
    cin >> size_a;
    cout << "Now, enter the numbers in the vector: (limit to " << size_a << " elements" << endl;
    for(int i=0, element; i<size_a; i++){
	cin >> element;
	a.push_back(element);
    }

    //fill vector b
    cout << "Enter the size of the 'b' vector you like to use: " << endl;
    cin >> size_b;
    cout << "Now, enter the numbers in the vector: (limit to " << size_b << " elements" << endl;
    for(int i=0, element; i<size_b; i++){
	cin >> element;
	b.push_back(element);
    }


    //compare a and b
    auto ia = a.begin(), ib = b.begin();  //iterator that transvering a and b
    while(ia != a.end() && ib!=b.end()){
        if(*ia < *ib){
	    cout << "vector b is larger than vector a" << endl;
	    return 0;
	}
	else if(*ia > *ib){
	    cout << "vector a is larger than vector b" << endl;
	    return 0;
  	}
	else{
	    ia++; ib++;
        }
    }

    if(ia == a.end() && ib == b.end()) cout << "vector a and b are equal" << endl;
    else if(ia == a.end()) cout << "vector b is larger than vector a " << endl;
    else cout << "vector a is larger than vector b" << endl;

    return 0;
}
