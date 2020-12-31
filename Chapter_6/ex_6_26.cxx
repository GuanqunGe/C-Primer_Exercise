#include <iostream>

int main(int argc, char **argv){

    auto begin = argv+1;  //to avoid the case where the first element in argv is empty string

    while(*begin){  //loop over element of array argv, until you see 0.
		    //passing 0 as argument won't cause this to stop, 
		    //as 0 in argument will be "0" in argv string array
	std::cout << *begin++ << std::endl;
    }

    return 0;
}
