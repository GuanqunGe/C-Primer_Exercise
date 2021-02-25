#include <iostream>
#include <map>
#include <string>
#include <functional>

int multiply(int a, int b){ return a * b;}

struct power{
    int operator()(int b, int e){
	int result = b;
	for(int i=1; i < e; ++i)
	    result *= b;
 	return result;
    }
};


int main(){

    auto divide = [](int a, int b){return a/b; };

    std::map<std::string, std::function<int(int, int)>> ops = {
	{"+", std::plus<int>()},
	{"-", [](int i, int j){return i-j;}},
	{"*", multiply},
	{"/", divide}
    };

    ops.insert({"^", power()}); 

    std::cout << "ops[\"+\"](10, 5) = " << ops["+"](10, 5) << std::endl;
    std::cout << "ops[\"-\"](10, 5) = " << ops["-"](10, 5) << std::endl;
    std::cout << "ops[\"*\"](10, 5) = " << ops["*"](10, 5) << std::endl;
    std::cout << "ops[\"/\"](10, 5) = " << ops["/"](10, 5) << std::endl;
    std::cout << "ops[\"^\"](2, 5) = " << ops["^"](2, 5) << std::endl;

    return 0;
}
