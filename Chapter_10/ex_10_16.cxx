#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void biggies(std::vector<std::string> &words, unsigned sz){

    std::sort(words.begin(), words.end()); // sort in alph order
    auto end_unique = std::unique(words.begin(), words.end()); //move up unique words
    words.erase(end_unique, words.end());

    //now words are in alph order, and are all unique
    //sort it into ascending size order, then alpha order
    std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2){return s1.size() < s2.size(); } );

    // find the first word with size >= sz
    auto end_find = std::find_if(words.cbegin(), words.cend(), [sz](const std::string &s) {return s.size() >= sz; } );

    unsigned count = words.end() - end_find;
    std::cout << count << " word(s) of length " << sz << " or longer"<< std::endl;

    // for each word in the range, print it out
    // two iterators in for_each should have the same type (in terms of constness)
    std::for_each(end_find, words.cend(), [](const std::string &s){ std::cout << s << " "; } );
    std::cout << std::endl;
}

int main(int argc, char **argv){
   
    if(argc < 2) {
	std::cerr << "Need an extra argument: filename" << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Couldn't open the file: " << argv[1] << std::endl;
	return -2;
    }

    std::vector<std::string> words;
    for(std::string word; infile >> word; words.push_back(word)) {}

    biggies(words, 5);

    biggies(words, 3);

    return 0;

}
