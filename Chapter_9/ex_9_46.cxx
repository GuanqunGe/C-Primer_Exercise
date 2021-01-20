#include <iostream>
#include <string>

using std::string;

string add_title(string name, const string &prefix, const string &suffix){

    name.insert(0, prefix + " ");
    name.insert( name.size(), " " + suffix);
    return name;
}

int main(){

    string name, prefix, suffix;
    std::cout << "please enter name, prefix, suffix " << std::endl;
    std::cin >> name >> prefix >> suffix;
    name = add_title(name, prefix, suffix);
    std::cout << "complete name: " << name << std::endl;

    return 0;
}
