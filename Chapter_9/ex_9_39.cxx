#include <vector>

int main(){

    std::vector<std::string> svec;
    svec.reserve(1024);  //reserve memory space large enough to hold at least 1024 strings
    std::string word;
    while(std::cin >> word)  // read strings from keyboard and add to svec
	svec.push_back(word); // if number of strings typed in exceeds its capacity, new memory will be allocated to hold original and new elements

    svec.resize(svec.size() + svec.size()/2); // change the size of vector to be 1.5 times larger
					      // new elements of empty strings will be added to the end of vector

    return 0;
}
