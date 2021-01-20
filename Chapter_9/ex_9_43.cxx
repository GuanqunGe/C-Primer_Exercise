#include <iostream>
#include <string>

using std::string;

// replace oldVal in s by newVal
void replace_substring(string &s, const string &oldVal, const string &newVal){

    if(oldVal.size() == 0){
	std::cerr << "String to be substituted is empty: " << oldVal << std::endl;
 	return ;
    }

    for(auto iter = s.begin(); iter != s.end(); ++iter){
	if( *iter != oldVal[0]) continue; //skip if it doesn't match the 1st character


	// if iter points to a char that matches the start of oldVal
	if( s.substr( iter - s.begin(), oldVal.size()) != oldVal) continue;

	// if instance of oldVal is seen
	// first, erase the oldVal
	//s.erase(iter - s.begin(), oldVal.size()); //can't do this, lost iterator.
	iter = s.erase( iter, iter + oldVal.size());

	// second, insert the newVal
	//s.insert( iter - s.begin(), newVal); // can't do this, lost iterator
	iter = s.insert( iter, newVal.begin(), newVal.end() );

	// note we only add iter by size()- 1 because of the expression ++iter in for loop
	iter += newVal.size() - 1;	

    } //end of for loop
}

int main(){

    string s;
    std::cout << "Please enter a string" << std::endl;
    getline(std::cin, s);
    string oldVal, newVal;
    std::cout << "Please enter two strings: oldVal newVal " << std::endl;
    std::cin >> oldVal >> newVal;
    replace_substring(s, oldVal, newVal);
    std::cout << "After substitution: \n" << s<< std::endl;
    return 0;
}
