#include <iostream>
#include <fstream>
#include <iterator>   // need to be included 
#include <vector>
#include <list>
#include <string>
#include <algorithm>

//print the list
std::ostream &print(std::ostream& os, const std::list<std::string> &lst){
    for(auto iter = lst.begin(); iter != lst.end(); ++iter)
	os << *iter << " ";
    return os;
}

int main(int argc, char **argv){
    if(argc < 2){
	std::cerr << "Need extra argument: filename" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    //read and fill the words vector
    std::vector<std::string> words;
    std::list<std::string> unq_lst, unq_lst2, unq_lst3;
    for(std::string s; infile >> s; ) {words.push_back(s); }

    // sort the words in alphabetical order, so that unique_copy can skip these consecutive duplicates
    std::sort(words.begin(), words.end());


    // 3 ways of inserting unique copys to another list
    // should I use std::back_inserter? yes I should 
    std::unique_copy(words.cbegin(), words.cend(), std::back_inserter(unq_lst));

    std::unique_copy(words.cbegin(), words.cend(), std::inserter(unq_lst2, unq_lst2.begin() )  );

    std::unique_copy(words.cbegin(), words.cend(), std::front_inserter(unq_lst3));

    print(std::cout, unq_lst) << "\n\n" << std::endl;
    print(std::cout, unq_lst2) << "\n\n" << std::endl;
    print(std::cout, unq_lst3) << "\n\n" << std::endl;

    return 0;
}
