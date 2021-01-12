#include <iostream>
#include <string>

class Tree{
    std::string type;  //type of the tree
    std::string name; //a name/mark for your tree
    unsigned age;    //age of the tree
    std::string address;  //where the tree is

    public:
     	Tree(std::string it, std::string in, unsigned ia, std::string id):type(it), name(in), age(ia), address(id){}
        Tree(std::string it, unsigned ia): Tree(it, "", ia, ""){}
	Tree(std::istream &in){
	    in >> type >> name >> age >> address;
	}

        //default constructor
	Tree(const std::string &s=""):Tree(s, "", 0, ""){}
};

int main(){
    return 0;
}
