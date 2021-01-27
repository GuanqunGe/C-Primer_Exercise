#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main(){

    std::list<std::string> str_lst;
    std::cout << "Please enter a list of strings " << std::endl;
    for(std::string s; std::cin >> s; ) str_lst.push_back(s);

    std::string str_to_find;
    std::cin.clear();
    std::cout << "Please enter a string to count " << std::endl;
    std::cin >> str_to_find;

    std::cout << str_to_find << " has appeared " << std::count(str_lst.begin(), str_lst.end(), str_to_find) << " times." << std::endl;

    return 0;
}
