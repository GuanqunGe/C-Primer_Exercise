#include <string>
#include <map>

int main(){
    std::map<std::string, size_t> word_count;
    std::string word;

    while(std::cin >> word)
	++word_count.insert({word, 0}).first->second;

    return 0;
}

// map.insert() calls member function of map, and returns a pair<iterator, bool>
// pair.first selects the data member of pair called 'first', which is an iterator of map element, which is also a pair
// iterator->second derefences the iterator and grabs the 'second' data member of the underlying object.
// So all of above are member selectors.
// ++ is the prefix increment, which has lower precedence than member selectors.
// given that member selectors are left associative, we can rewrite that expression as:
//  ++ (((word_count.insert( {word, 0} )).first)->second);
// so what it does is:
//  1. for a word that does not exist before, add the word to the map, set the count to 0, then increment the count by 1!
//  2. for a word that does exist in the map before, increment its count by 1. 
