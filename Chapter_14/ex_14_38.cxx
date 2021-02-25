#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>  //to use numeric_limits<>
#include <climits> //to use INT_MAX

class MatchBound{
public:
    MatchBound(int i1, int i2): lowerbound(i1), upperbound(i2){}
    bool operator()(const std::string &s) const{
	return s.size() >= lowerbound && s.size() <= upperbound;
    }

private:
    int upperbound;
    int lowerbound;
};

int main(int argc, char **argv){

    if(argc <2){
	std::cerr << "need extra file to read: filename" << std::endl;
    	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    std::istream_iterator<std::string> in_iter(infile), eof_iter;
    std::vector<std::string> vec(in_iter, eof_iter);

    int num = std::count_if(vec.cbegin(), vec.cend(), MatchBound(1, 10));
    std::cout << "There are " << num << " words that have length in between 1 and 10 inclusive" << std::endl; 

    //ex_14_39
    std::cout << "There are " << std::count_if(vec.cbegin(), vec.cend(), MatchBound(1,9)) << " words that are of length between 1 and 9 inclusive " << std::endl;
    std::cout << "And " << std::count_if(vec.cbegin(), vec.cend(), MatchBound(10, std::numeric_limits<int>::max() )) << " words that are of length 10 or more" << std::endl;
    std::cout << "And " << std::count_if(vec.cbegin(), vec.cend(), MatchBound(10, INT_MAX) ) << " words that are of length 10 or more" << std::endl;  //to use INT_MAX, need to include header <climits>

    return 0;
}
