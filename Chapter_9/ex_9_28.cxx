//write a function that insert the second string after where the first string is found

#include <iostream>
#include <forward_list>
#include <string>

using std::forward_list;
using std::string;
using std::ostream;

//print the list
ostream &print_lst(ostream &os, const forward_list<string> &flst){
    for(auto iter = flst.begin(); iter != flst.end(); ++iter)
	os << *iter << "  ";
    return os;
}

//find a string, and insert another string after it
void insert_string(forward_list<string> &flst, const string &s1, const string &s2){

    auto prev = flst.before_begin();//to grab the iterator to the last element, if string is not found
    bool found_string = false;

    // ++iter expression in the for loop update iter if element it points to doesn't match the string. Also avoids examining the newly inserted string if a matched string is found
    for(auto iter = flst.begin(); iter != flst.end(); ++iter, ++prev){
	if( *iter != s1) ;
	else{
	    found_string = true;
	    prev = iter;
	    iter = flst.insert_after(iter, s2);
	}
    }

    // if no string is found in the lst, insert after the very last element of the list
    if(!found_string) flst.insert_after(prev, s2);

}

int main(){
    forward_list<string> flst = {"andre", "andrew", "anthony", "benedict", "andrew", "charlie"};
    print_lst(std::cout, flst) << std::endl;

    string str_to_found, str_to_insert;
    std::cout << "Please enter the string you want to find and insert: " << std::endl;
    std::cin >> str_to_found >> str_to_insert;
    insert_string(flst, str_to_found, str_to_insert);

    print_lst(std::cout, flst) << std::endl;

    return 0;    
}

