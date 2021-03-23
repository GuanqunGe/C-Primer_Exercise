#include <iostream>
#include <string>
#include <vector>
#include <list>

template <typename iterator, typename T2>
iterator Find(iterator begin, iterator end, const T2 &val){

    while( begin != end){
	if( *begin == val) return begin;
 	++begin;
    }
    return begin;
}

int main(){
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    auto vec_pos = Find(vec.begin(), vec.end(), 6);
    if(vec_pos == vec.end()){
	std::cout << "6 is not in the vector" << std::endl;
    }else{
	std::cout << "6 is the " << vec_pos - vec.begin() << "th element in the vector" << std::endl;
    }


   std::list<std::string> lst{"Sunday", "March", "Weather", "Quite", "Nice", "I", "am", "Joking"};
   auto lst_pos = Find(lst.begin(), lst.end(), "I");
   if(lst_pos == lst.end()){
	std::cout << "\"I\" is not in the list" << std::endl;
   }
   else{
	std::cout << *lst_pos << std::endl;
   }

   return 0;
}
