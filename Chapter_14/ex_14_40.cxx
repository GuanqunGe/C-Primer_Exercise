#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using std::vector;
using std::string;

//compare length of two strings
struct Compare{
    bool operator()(const std::string &s1, const std::string &s2){
	return s1.size() < s2.size();
    }
};

//compare if length of string is larger than given number
class LongerThan{
public:
    using size_type = std::string::size_type;
    LongerThan(size_type n): sz(n){}
    bool operator()(const std::string &s) const{
	return s.size() >= sz;
    }
private:
    size_type sz;
};

//print the strings
class Print{
public:
    Print(std::ostream &out = std::cout, char c=' '): os(out), delimiter(c){}
    void operator()(const std::string &s){
	os << s << delimiter;
    }

private:
    std::ostream &os;
    char delimiter;
};

//eliminate duplicates in vector of string
void elimDups(vector<string> &vec){

    std::sort(vec.begin(), vec.end());
    auto uniq_end = std::unique(vec.begin(),vec.end());
    vec.erase(uniq_end, vec.end());
}

void biggies(vector<string> &vec, vector<string>::size_type sz){
    elimDups(vec);

    std::stable_sort(vec.begin(), vec.end(), Compare());

    auto pos = std::find_if(vec.begin(), vec.end(), LongerThan(sz));
    auto count = vec.end() - pos;
    std::cout << count << " words of length " << sz << " or longer." << std::endl;

    std::for_each(pos, vec.end(), Print(std::cout, '\n'));
    //std::for_each(pos, vec.end(), Print(std::cout, ' '));
    std::cout << std::endl;
}

int main(int argc, char **argv){
    if(argc < 2){
	std::cerr << "Need extra file: filename" << std::endl;
 	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
	return -2;
    }

    std::istream_iterator<std::string> in_iter(infile), eof_iter;
    std::vector<std::string> vec(in_iter, eof_iter);

    biggies(vec, 7);
    infile.close();
    return 0;
}
