#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){

    vector<int> ints{1, 2, 3, 4, 5 ,6 ,7};

    //print out the original vector
    cout << "Original vector: ";
    for(const auto &val : ints)
        cout << val << " ";
    cout << endl;


    //change the odd elements and double them
    for(auto &val : ints){
	// approach 1
        //val = (val%2==0) ? val : (2*val);
        
        //approach 2
        //(val%2 == 0) ? : val*=2;   //I thought it's wrong, since *= has lower precedence than ?: but it still produces the correct result
        (val%2 == 0) ? : (val*=2);   //correct
    }

    //print out the changed vector
    cout << "Changed vector: " ;
    for(const auto &val: ints)
	cout << val << " ";
    cout << endl;


    return 0;
}
