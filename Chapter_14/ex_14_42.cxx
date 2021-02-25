#include <iostream>
#include <vector>
#include <string>
#include <functional> //to use bind, and library function class
#include <algorithm>

using namespace std::placeholders;

int main(){

    std::vector<std::string> svec{"like", "hate", "love","pooh", "rain"};
    std::vector<int> ivec{0, 1, 1025, 89, 781, 1300};

    auto count = std::count_if(ivec.begin(), ivec.end(), std::bind(std::greater<int>(), _1, 1024));
    std::cout << count << (count > 1 ? "numbers" : "number") << " that are larger than 1024" << std::endl;

    auto pos = std::find_if(svec.begin(), svec.end(), std::bind(std::equal_to<std::string>(), _1, "pooh"));
    //auto pos = std::find_if(svec.begin(), svec.end(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    if( pos != svec.end()) std::cout << "First word not equal to \"pooh\" is : " << *pos << std::endl;


    //std::for_each(ivec.begin(), ivec.end(), std::bind(std::multiplies<int>(), _1, 2 )); //this does not change the element
    std::transform(ivec.begin(), ivec.end(), ivec.begin(),  std::bind(std::multiplies<int>(), _1, 2 ));
    std::for_each(ivec.begin(), ivec.end(), [](int n){std::cout << n << " "; } );
    std::cout << std::endl;

    return 0;
}
