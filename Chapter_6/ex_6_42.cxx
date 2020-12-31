#include <iostream>
#include <string> 

using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s"){
    return (ctr >1 ) ? word+ending : word;
}

int main(){

    std::cout << "singular version of success is : " << make_plural(1, "success") << std::endl;
    std::cout << "plural version of success is : " << make_plural(2, "success", "es") << std::endl;
    std::cout << "singular version of failure is : " << make_plural(1, "failure") << std::endl;
    std::cout << "plural version of failure is : " << make_plural(2, "failure") << std::endl;
    return 0;
}
