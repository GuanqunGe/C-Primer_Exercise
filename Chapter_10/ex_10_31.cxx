#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main(){

    std::cout << "Please enter a list of integers " << std::endl;
    std::istream_iterator<int> in(std::cin), in_eof;

    std::deque<int> deq(in, in_eof);

    //sort numbers
    std::sort(deq.begin(), deq.end());

    //print out unique element
    std::ostream_iterator<int> out(std::cout, " ");
    std::unique_copy(deq.cbegin(), deq.cend(), out);
    std::cout << std::endl;

    return 0;
}
