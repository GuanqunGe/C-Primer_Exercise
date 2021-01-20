#include <iostream>
#include <vector>

int main(){
    std::vector<int> iv{1, 2, 3, 4, 5, 6};
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

    int some_val = 3;
    while(iter != mid){
        if( *iter == some_val){
	    iv.insert(iter, 2*some_val);
	    break;  //after inserting the element, break from the loop
		    // because iterators might be invalidated after insertion 
	}
	++iter;  //update the iterator
    }

    for(iter = iv.begin(); iter != iv.end(); ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}
