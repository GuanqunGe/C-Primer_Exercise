#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;

void Print(const std::vector<std::string> &vec){
    for(auto &e : vec)
	std::cout << e << " ";
    std::cout << std::endl;
}

int main(){
    vector<string> names; //empty
    list<const char *> lst_names{"James", "Tom", "Daniel", "Yumi", "Jess"};

    names.assign(lst_names.cbegin(), lst_names.cend()); //assign(b, e)
    Print(names);

    names.assign({"Sara", "Vic"}); //assign(lst)
    Print(names);

    names.assign(10, "Davio"); //assign(n ,t)
    Print(names);    
    return 0;
}
