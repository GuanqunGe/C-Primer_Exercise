//I added assignment operator that takes a const reference to std::string, b/c one of the constructor of this class
//takes one argument that has type 'const std::string &', just thought it would be nice to allow implicit conversion
//from std::string to the class type.
#include <iostream>
#include <string>

class Tree{
    friend std::istream& operator>>(std::istream&, Tree&);
    friend std::ostream& operator<<(std::ostream&, const Tree&);
    friend bool operator==(const Tree&, const Tree&);
    friend bool operator!=(const Tree&, const Tree&);
public:
    Tree(std::string it, std::string in, unsigned ia, std::string id):type(it), name(in), age(ia), address(id){}
    Tree(std::string it, unsigned ia):type(it), age(ia){}
    Tree(std::istream &in){
	    in >> type >> name >> age >> address;
    }

    //default constructor
    Tree(const std::string &s=""):type(s),age(0){}
    Tree &operator=(const std::string &);

private:
    std::string type;  //type of the tree
    std::string name; //a name/mark for your tree
    unsigned age;    //age of the tree
    std::string address;  //where the tree is
        
};

std::ostream& operator<<(std::ostream &os, const Tree &t){
    os << t.type << " " << t.name << " " << t.age << " " << t.address;
    return os;
}

std::istream& operator>>(std::istream &is, Tree &t){
    is >> t.type >> t.name >> t.age >> t.address; //if status of istream is bad, this line won't do anything
    if(!is)  t = Tree();    //if status of istram is bad, this will run
    return is;
}

//note that this function is not ambigious!
Tree &Tree::operator=(const std::string &s){
    std::cout << "Tree &Tree::operator=(string&)" << std::endl;
    type = s;
    name ="";
    age=0;
    address="";
    return *this;
}

bool operator==(const Tree &lhs, const Tree &rhs){
    return lhs.type == rhs.type && lhs.name == rhs.name && lhs.age == rhs.age && lhs.address == rhs.address;
}

bool operator!=(const Tree &lhs, const Tree &rhs){
    return !(lhs== rhs);
}

int main(){

    Tree t1("Coconut Tree", "Jess", 40, "NY");
    Tree t2;
    Tree t3(std::cin);
    std::cin >> t2;

    Tree t4 = t1;
    t4 = "xMAS TREE";
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;
    std::cout << t4 << std::endl;

    std::cout << "t1 == t4: " << (t1 == t4 ? "true" : "false" ) << std::endl;
    std::cout << "t2 != t3: " << (t2 != t3 ? "true" : "false" ) << std::endl;
    return 0;
}
