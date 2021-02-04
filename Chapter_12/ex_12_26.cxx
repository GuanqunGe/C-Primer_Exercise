#include <iostream>
#include <string>
#include <memory>
#include <iterator>

int main(){

    std::cout << "please enter how much memory space u want to allocate: " << std::endl;
    int size;
    std::cin >> size;

    std::allocator<std::string> alloc;
    std::string * const p = alloc.allocate(size);


    //method 1 -- directly fill the array
    auto q = p;
    for( std::string s; std::cin >> s && q != p+size; )
 	alloc.construct(q++, s);

/*
    //method 2 -- use istream_iterator to fill the array
    std::istream_iterator<std::string> in_iter(std::cin), in_eof;
    auto q = std::uninitialized_copy( in_iter, in_eof, p);
*/

    std::cout << "print it out: " << std::endl;
    for( auto iter = p; iter != q; ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;

    //free the memory
    while( q != p)
	alloc.destroy(--q);
    alloc.deallocate(p, size);

    //delete [] p; //wrong, can't use this to free the memory anymore

    return 0;
}
