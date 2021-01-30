#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::vector;
using std::map;
using std::string;

int main(){

    map<string, vector<int>> m = {{"Andrew", {1990, 7, 13}}, {"Kathryn", {1999, 5,24}},
				  {"Gretchen", {1997, 5, 20}}, {"Ryan", {1998, 8, 4}}};

    string name_to_find;
    std::cin >> name_to_find;

    //find returns an iterator refering to first element with given key
    map<string, vector<int>>::iterator pos = m.find(name_to_find);

    if(pos != m.end()){
	std::cout << "Found name: " << name_to_find << ", B-day: ";
	for(const auto &d: pos->second)
	    std::cout << d << " ";
	std::cout << std::endl;
    }else{
	std::cout << name_to_find << " is not in the map" << std::endl;
    }

    return 0;
}
