#include <vector>
#include <iostream>
#include <list>

// print list
std::ostream &print_lst(std::ostream& os, const std::list<int> &lst){
    for(auto iter = lst.begin(); iter != lst.end(); ++iter)
	os << *iter << " ";
    return os;
}

// print vector
std::ostream &print_vec(std::ostream &os, const std::vector<int> &vec){
    for(decltype(vec.size()) i=0; i!= vec.size(); ++i)
	os << vec.at(i) << " ";
    return os;
}


int main(){
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> ivec;
    std::list<int> ilst;

    // copy values from array, to list and vectors
    // !!!!! can also copy using iterators!!!!
    //  std::vector<int> ivec( std::begin(ia), std::end(ia));
    //  std::list<int> ilst( std::begin(ia), std::end(ia));
    for(const auto &i : ia){
 	ivec.push_back(i);
	ilst.push_back(i);
    }

    
    print_vec(std::cout, ivec) << std::endl;
    // erase even-valued elements
    for(auto iter = ivec.begin(); iter != ivec.end(); ){
	if(*iter % 2 == 0 ) 
	    iter = ivec.erase(iter);
        else ++iter;
    }
    print_vec(std::cout, ivec) << std::endl;

    print_lst(std::cout, ilst) << std::endl;
    // erase odd-valued elements
    for(auto iter = ilst.begin(); iter != ilst.end(); ){
	if( *iter %2)
	    iter = ilst.erase(iter);
        else ++iter;
    }
    print_lst(std::cout, ilst) << std::endl;

    return 0;

}
