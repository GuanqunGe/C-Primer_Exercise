#include <iostream>
#include <list>
#include <string>

int main(){
    std::list<std::string> deq;
    for( std::string word; std::cin >> word; ) 
	//deq.push_back(word); //put the word at the end of deque
 	deq.push_front(word); //push the word in front of the beginning of the deque

    for(auto iter = deq.cbegin(); iter != deq.cend(); ++iter)
	std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}

/***********
 * two places need to change:
 * header file: <deque> --> <list>
 * declaration of deq: std::deque --> std::list
 */
