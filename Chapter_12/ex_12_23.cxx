#include <iostream>
#include <string>
#include <cstring> //to use strlen, strcpy, strcat

char *Concatenate(const char *p1, const char *p2){

    // 1 extra space to hold '\0'
    size_t total_length = std::strlen(p1) + std::strlen(p2) + 1;
    char *out = new char[total_length];


    //fill the array --method 1
    //out should be treated just like a normal char pointer
    //except that you need to delete the memory associated with it when necessary
    std::strcpy(out, p1);
    std::strcat(out, p2);

/*    //fill the array  -- method 2
    for( size_t i = 0; i< std::strlen(p1) ; ++i)
	out[i] = p1[i];

    for( size_t i = 0; i < std::strlen(p2); ++i)
	out[std::strlen(p1) + i] = p2[i];

    out[total_length - 1] = '\0';
*/
    return out;
}

int main(){

    char *p = Concatenate("hello", "world");
    std::cout << p << std::endl;


    std::string s1 = "hello", s2 = "world";
    std::cout << s1 + s2 << std::endl;

    delete [] p;
    return 0;
}
