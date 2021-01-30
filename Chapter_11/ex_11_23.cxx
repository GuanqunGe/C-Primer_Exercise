#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using std::multimap;
using std::string;
using std::vector;
// directly add a family to the multimap
void add_family(std::istream &is, multimap<string, vector<string>> &imap){

    std::cout << "please enter info in following format: family_name kid1_name kid2_name... " << std::endl;
    string family_str;
    while(getline(is, family_str)){
	string family_name;
	vector<string> children_name;

	std::istringstream ss(family_str);
	ss >> family_name;
	for( string name; ss >> name; ) children_name.push_back(name);

        imap.insert( {family_name, children_name} ); //multimap does not have subscript operator
    }
}

// add a name, direct insert to the multimap
void add_kid(multimap<string, vector<string>> &imap, const string &last_name, const string &kid_name){
    imap.insert( {last_name, vector<string>{kid_name}  });
}


// print the map
std::ostream &print(std::ostream &os, const multimap<string, vector<string>> &imap){

    for(const auto &p: imap){
	os << p.first << ": ";
	for(auto &name : p.second)
	    os << name << " ";
        os << "\n";
    }

    return os;
}


int main(){

    multimap<string, vector<string>> families;

    add_family(std::cin, families);

    print(std::cout, families) << std::endl;

    add_kid(families, "Greene", "Jess");

    print(std::cout, families) << std::endl;

    return 0;
}
