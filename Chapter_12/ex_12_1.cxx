#include "include/StrBlob.h"

int main(){

    StrBlob b1; //empty b1: b1.data points to empty vector
    {
	//explicit construction
	//StrBlob b2{"a", "an", "the"};

	//implicit conversion
	StrBlob b2 = {"a", "an", "the"}; // b2.data points to a vector of 3 strings

	b1 = b2; // assign b2.data to b1.data, 
		//now b1.data and b2.data both point to the same dynamically allocated vector
	b2.push_back("about"); //add 1 element to the dynamically allocatd vector
    }
    // b2 is out of scope
    // b1 is still in scope, b1.data is the shared_ptr that points to the dynamically allocated vector, which has 4 elemnts.
    
    return 0;
}
