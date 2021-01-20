// write a program to copy elements from a list<int> into two deques
// the even-valued element should go into one deque and the odd ones into the other

#include <iostream>
#include <deque>
#include <list>

// divide list into two parts
void divide_list(const std::list<int> &lst, std::deque<int> &deq_even, std::deque<int> &deq_odd){
    
    for( auto iter = lst.begin(); iter != lst.end(); ++iter){
	if( *iter % 2)  // % operator has higher precedence than % 
	    deq_odd.push_back(*iter);
	else
	    deq_even.push_back(*iter);
    }

}

// print the deque
std::ostream &print(std::ostream &os, const std::deque<int> &deq){
    for(auto iter = deq.begin(); iter != deq.end(); ++iter)
	os << *iter << " ";
    return os;
}

int main(){
    std::deque<int> deq1, deq2, deq3, deq4;
    std::list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    divide_list(lst, deq1, deq2);
    divide_list({-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, deq3, deq4);

    print(std::cout, deq1) << std::endl;
    print(std::cout, deq2) << std::endl;
    print(std::cout, deq3) << std::endl;
    print(std::cout, deq4) << std::endl;
 
    return 0;
}
