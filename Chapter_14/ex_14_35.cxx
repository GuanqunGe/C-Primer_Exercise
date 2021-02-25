#include <iostream>
#include <vector>
#include <string>

class ReadString{
public:
    //copy-control members will be synthesized by compiler

    std::string &operator()(std::istream&);
    const std::string &GetStr() const {return str; }
private:
    std::string str;
};

std::string& ReadString::operator()(std::istream &is){
    if(!std::getline(is, str))
	str=""; 
    return str;
}

//------------------ end of class implementation ----------

int main(){

    ReadString rs;
    std::cout << rs(std::cin) << std::endl;
 
    //By return string&, s2 will be able to modify data member in rs.
    std::string &s2 = rs(std::cin);
    std::cout << rs.GetStr() << std::endl;
    s2 = "hello";
    std::cout << s2 << std::endl;
    std::cout << rs.GetStr() << std::endl;


    //ex_14_36
    std::vector<std::string> vec;
    while(std::cin){
  	//note that, the last element in vec will be an empty string
	vec.push_back(std::move( rs(std::cin) ));
    }

    for(const auto& e:vec)
	std::cout << e << " ";
    std::cout << std::endl;

    std::cout << s2 << std::endl; //after move constructor, str in rs is now empty
    return 0;
}
