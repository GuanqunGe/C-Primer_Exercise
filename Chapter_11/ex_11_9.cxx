#include <iostream>
#include <string>
#include <map>
#include <list>

int main(){

    std::map<std::string, std::list<unsigned>> word_line = {
	{"We", {1, 5, 89, 23}}, {"Left", {1, 2, 4, 56}},
	{"and", {3, 4, 6, 8}}, {"include", {2, 4, 5, 6, 7}}
    };

    for(const auto &pair: word_line){
	std::cout << pair.first << " has appeared on line ";
	for( auto &i : pair.second)
	    std::cout << i << " ";
	std::cout << std::endl;
    }

    return 0;
}
