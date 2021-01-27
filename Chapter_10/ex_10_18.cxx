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

    //group words with length longer than sz in the first part
    auto end_partition = std::partition(words.begin(), words.end(), [sz](const std::string &s) {return s.size() >= sz; });

    // sort words alphabetically
    std::sort(words.begin(), end_partition);  //after sort, end_partition seems to be still valid.

    // stable_sort word by size
    std::stable_sort(words.begin(), end_partition, [](const std::string &s1, const std::string &s2) {return s1.size() < s2.size();});

    unsigned count = end_partition - words.begin();
    std::cout << count << " word(s) of length " << sz << " or longer"<< std::endl;

    // for each word in the range, print it out
    std::for_each(words.begin(), end_partition, [](const std::string &s){ std::cout << s << " "; } );
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
