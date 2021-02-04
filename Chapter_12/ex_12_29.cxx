#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

void fill_map( std::map<std::string, std::multiset<unsigned>> &inmap, std::vector<std::string> &vstr, std::ifstream &infile){

    std::string line;
    while( std::getline(infile, line)){
	std::istringstream ss(line);
	for(std::string word; ss >> word; )
	    inmap[word].insert(vstr.size());

	vstr.push_back(line);
    }
}

int main(int argc, char **argv){
    if(argc < 2) {
	std::cerr << "Need an extra file: " << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    std::map<std::string, std::multiset<unsigned>> map;
    std::vector<std::string> lines;
    fill_map( map, lines, infile);


    std::cout << "Enter a word you want to query:" << std::endl;
    std::string word;
    std::cin >> word;

    do{
	auto pos = map.find(word);
   	if(pos == map.end()){
	    std::cout << word << " occurs 0 time" << std::endl;
 	}else{
	     const auto &line_numbers = pos->second;
	     unsigned count = line_numbers.size();
	     std::cout << word << " occurs " << count << (count > 1? " times": "time") << std::endl;

	     auto iter = line_numbers.begin();
	     while( iter != line_numbers.end()){
		std::cout << "(line " << *iter +1 << ") " << lines[*iter] << std::endl;
		iter = line_numbers.upper_bound( *iter );
	     }    
  	}
	std::cout << std::endl;

        std::cout << "Enter a word you want to query: (enter q to quit) " << std::endl;
	std::cin >> word;
    }while( std::cin && word != "q");

    infile.close();
    return 0;
}

//I like the single while loop better, as in that way as a user, I have control even for the first loop
