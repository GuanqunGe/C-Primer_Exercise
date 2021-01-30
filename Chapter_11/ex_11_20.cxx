#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, unsigned> word_count;

    std::cout << "please enter a list of words to process " << std::endl;
    for(std::string word; std::cin >> word; ){
	auto result = word_count.insert( {word, 1});
	if(!result.second){ //if the pair is not inserted, meaning existent key in the map
	    ++(result.first)->second;
        }
    }


    std::cout << "\nword of frequency" << std::endl;
    for(const auto &p : word_count){
    // for( auto p : word_count){  //type of p: pair<const string, unsigned>
	std::cout << p.first << ": " << p.second << std::endl;
    }
 
    return 0;
}

// using subscript to add count of words is easier, as the map automatically takes care of the case where key does not exist in the map.
