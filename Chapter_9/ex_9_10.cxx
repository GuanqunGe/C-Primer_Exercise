#include <vector>

int main(){
    std::vector<int> v1;
    const std::vector<int> v2;

    //auto it1 = v1.begin(), it2 = v2.begin(); // it1 is std::vector<int>::iterator, it2 is std::vector<int>::const_iterator, so this statment is wrong.
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();  // it3 and it4 both are std::vector<int>::const_iterator

    return 0;
}
