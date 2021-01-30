#include <iostream>
#include <map>

int main(){

    std::map<int, unsigned> imap= {{1, 1}, {2,2}, {3,3}, {4,4}};
    for(std::map<int, unsigned>::iterator iter = imap.begin(); iter != imap.end(); ++iter){
	if(iter->first == 3) iter->second = 5;
    }

    imap[3] = 6;

    for(auto &p:imap){  //p is a reference to std::pair<const int, unsigned>
	//p.first = 0; //wrong, can't change a read-only member
	std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}
