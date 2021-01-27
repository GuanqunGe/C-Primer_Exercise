#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main(){

    std::cout << "Please enter a list of integers " << std::endl;
    // getting input from keyboard will start right away after definition of istream_iterator
    // so need to print instructional info before defining istream_iterator
    std::istream_iterator<int> in(std::cin), in_eof;

    //note: sort() requires random excess to elements, so sort() can't be used with list
    std::deque<int> deq(in, in_eof);

    //sort numbers
    std::sort(deq.begin(), deq.end());

    //print out
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(deq.cbegin(), deq.cend(), out);
    std::cout << std::endl;

    return 0;
}
