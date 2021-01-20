#include <iostream>
#include <string>

using std::string;

// replace oldVal in s by newVal, using index and replace
// this function is not good enough, if oldVal sits INSIDE newVal (eg, oldVal = abs, newVal = fabs)
// then this function will never end!! 
void replace_substring_v0(string &s, const string &oldVal, const string &newVal){

    if(oldVal.size() == 0){
	std::cerr << "String to be substituted is empty: " << oldVal << std::endl;
 	return ;
    }

    for(auto iter = s.begin(); iter != s.end(); ++iter){
	if( *iter != oldVal[0]) continue; //skip if it doesn't match the 1st character


	// if iter points to a char that matches the start of oldVal
	if( s.substr( iter - s.begin(), oldVal.size()) != oldVal) continue;
	else{
	    // if we see an instance of oldVal

	    // if seeing an oldVal is due to the fact that oldVal is part of the newVal, skip it
	    // we don't want to be caught in the loop
	    if( s.substr( iter -s.begin(), newVal.size()) == newVal){
		iter += newVal.size() - 1;
		continue;
	    }else{
		//if we just see oldVal
		s.replace( iter - s.begin(), oldVal.size(), newVal);
		replace_substring_v0(s, oldVal, newVal); //run this function in a loop
	    }
	} // end of else

    } //end of for loop
}

// version 1 of function that replaces oldVal in s by newVal
// simply replace oldVal by newVal, don't care if newVal and oldVal overlap
void replace_substring_v1(string &s, const string &oldVal, const string &newVal){

    if(oldVal.size() == 0){
	std::cerr << "String to be substituted is empty: " << oldVal << std::endl;
 	return ;
    }

    for(auto iter = s.begin(); iter != s.end(); ++iter){
	if( *iter != oldVal[0]) continue; //skip if it doesn't match the 1st character


	// if iter points to a char that matches the start of oldVal
	if( s.substr( iter - s.begin(), oldVal.size()) != oldVal) continue;
	else{
	    // if we see an instance of oldVal

	    // remember where the iterator should be after insertion/replacement
	    int new_index = iter - s.begin() + static_cast<int>(newVal.size()) - 1;
	    s.replace( iter - s.begin(), oldVal.size(), newVal);

	    iter = s.begin() + new_index; //reassign iterator
	} // end of else

    } //end of for loop
}

//function replace_substring_v1 could also be rewritten using index
// ie. for(decltype(s.size()) p = 0; p != s.size(); ++p)
//     /* .. operations using p... */
// One advantage of using index is that it will not be invalidated after erasion/insertion/replacement.


int main(){

    string s;
    std::cout << "Please enter a string" << std::endl;
    getline(std::cin, s);
    string oldVal, newVal;
    std::cout << "Please enter two strings: oldVal newVal " << std::endl;
    std::cin >> oldVal >> newVal;
    replace_substring_v1(s, oldVal, newVal);
    std::cout << "After substitution: \n" << s<< std::endl;
    return 0;
}
