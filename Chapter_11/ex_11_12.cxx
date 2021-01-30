#include <iostream>
#include <string>
#include <utility> // to use pair
#include <vector>

int main(){

    std::vector<std::pair<std::string, int>> vec_pairs;

    std::string str;
    int i;
    //read from input, make pairs and push to vector
    while(std::cin >> str >> i){
	// method 1
	vec_pairs.push_back( std::make_pair(str, i) );

	//method 2
	vec_pairs.push_back( std::pair<std::string, int>(str, i) );

 	// method 3
 	vec_pairs.push_back( std::pair<std::string, int>{str, i} );

	// method 4 - list initializatoin
	vec_pairs.push_back( {str, i} );
    }

    // print out each element (pair)
    for(const auto &p : vec_pairs){
	std::cout << p.first << ": " << p.second << std::endl;
    }

    return 0;
}
