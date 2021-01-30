#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::map;
using std::vector;
using std::string;
using std::pair;

void add_families(std::istream &is, map<string, vector<pair<string, string>>> &map){

   // stream should follow the format of: family name, child name, child birthday.....
   string each_family;
   while(getline(is, each_family)){
	std::istringstream ss(each_family);
	string family_name;
	ss >> family_name;

	for(string child_name, child_birth; ss >> child_name >> child_birth; )
	    map[family_name].push_back( std::make_pair(child_name, child_birth));
   }

}

void add_child(map<string, vector<pair<string, string>>> &map, const string &family_name, const string &kid_name, const string &kid_birth){
    auto child_vec = map[family_name]; // if family name doesn't exist yet, will create a new one, and return empty vector
    if( std::find(child_vec.cbegin(), child_vec.cend(), std::make_pair(kid_name, kid_birth)) != child_vec.cend() ){
	std::cout << "Child: " << kid_name << ", birthday: " << kid_birth << " already in there" << std::endl;
    }else{
	map[family_name].push_back(std::make_pair(kid_name, kid_birth));
    }
}

std::ostream &print(std::ostream &os, const map<string, vector<pair<string, string>>> &map){
    for(auto &p : map){
	// for each family in the map
	os << p.first << ": ";
	for(auto &kid : p.second){ // loop over each kid
	    os << kid.first << "-" << kid.second << " ";
	}
	os << "\n";
    }

    return os;
}

int main(){
    map<string, vector<pair<string, string>>> families;
   
    std::cout << "Please enter family info: last name kid name kid birthday ... " << std::endl; 
    add_families(std::cin, families);

    print(std::cout, families) << std::endl;

    add_child(families, "Zhang", "Jerry", "01/23/1995");

    print(std::cout, families) << std::endl;

    return 0;
}
