#include <iostream>
#include <deque>
#include <string>

int main(){
    std::deque<std::string> deq;
    for( std::string word; std::cin >> word; ) 
	//deq.push_back(word); //put the word at the end of deque
 	deq.push_front(word); //push the word in front of the beginning of the deque

    for(auto iter = deq.cbegin(); iter != deq.cend(); ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}
