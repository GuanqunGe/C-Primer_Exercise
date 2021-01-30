#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main(){

    std::multiset<std::string> c;
    std::vector<std::string> v;


    //tranverse through v, copy each element to the end of c, correct
    std::copy(v.begin(), v.end(), std::inserter(c, c.end()) );

    //wrong, it tries to add the copy of each element in v to the end of c, but multiset is associative container
    //thus does not have push_back() member function
    //std::copy(v.begin(), v.end(), std::back_inserter(c));

    //correct. tranverse through container c, and add copy of each key/element in c to the end of v.
    std::copy(c.begin(), c.end(), std::inserter(v, v.end()) );

    //correct, add copy of each key in c to the end of v.
    std::copy(c.begin(), c.end(), std::back_inserter(v));

    return 0;
}
