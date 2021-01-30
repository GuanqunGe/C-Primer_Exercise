#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main(){

    std::vector<std::string> exclude = {"The", "An", "And", "A",
					"the", "an", "and", "a"};
    std::map<std::string, unsigned> word_count;

    std::cout << "Please enter a list of words to count" << std::endl;
    for(std::string s ; std::cin >> s ; ){
	if(std::find(exclude.cbegin(), exclude.cend(), s) == exclude.cend())
	    ++word_count[s];
    }

    for(const auto &pair : word_count){
	std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

// first advatange I can think of is that, when querying an value in the sequence, vector would need generic algorithms to do so, while set itself has member function to achieve that.
// set allows efficient look up as the key acts like a subscript, while in vectors, in order to query an element, we need to tranverse through an order of N elements (N is the size of vector).
