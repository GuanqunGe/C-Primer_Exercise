#include <iostream>
#include <sstream>
#include <iterator> //to use istream_iterator
#include <string>
#include <map>
#include <vector>

int main(){

    std::map<std::string, std::vector<std::string>> FamilyMap; //empty map

    std::cout << "Please enter family last name, followed by children's names" << std::endl;
    std::string family_string;
    while(getline(std::cin, family_string)){
	std::istringstream ss(family_string);
	std::string last_name;
	std::vector<std::string> kids_name;
	ss >> last_name;

	// Push back children's name, so if there is existent key, the value won't be overwritten, instead value vector will be extended
	// if the key does not exist, a new element will be created with that key.
	for(std::string name; ss>>name; ) {FamilyMap[last_name].push_back(name); }

	//for(std::string name ; ss >> name;) {kids_name.push_back(name); }
	//FamilyMap[last_name] = kids_name; // if there is an existent key in the map, value is overwritten.
    }

/*  
    int num_family;
    std::cout << "Enter the number of family entries" << std::endl;
    std::cin >> num_family;
 
    std::cout << "Now, please enter family last name, followed by children's names" << std::endl;
    // does not work
    for(int i = 0; i < num_family; ++i){
	std::istream_iterator<std::string> in_iter(std::cin), in_eof;
	// question: left or right, which side is evaluated first?
	// assignment expressions are evaluated from right to left
	FamilyMap[*in_iter++] = std::vector<std::string>(in_iter, in_eof);
    }
*/

    std::cout << "Print the info out" << std::endl;
    std::cout << "size of map: " << FamilyMap.size() << std::endl;

    // note that the order of pairs printed out is not the same as input order
    for(const auto &pair: FamilyMap){
	std::cout << "Last Name: " << pair.first << ", children's names: ";
	for(auto &s: pair.second)
	    std::cout << s << " ";
 	std::cout << std::endl;
    }

    return 0;
}
