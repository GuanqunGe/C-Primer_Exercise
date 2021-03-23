#include <iostream>


template <typename T, unsigned N>
T* begin(T (&array)[N]){
    return array; //both return statements are ok.
    //return &array[0];
}

template <typename T, unsigned N>
T* end(T (&array)[N]){
    return array+N;
}


int main(){

    int arr[] = {1,2,3,4,5,6};
    auto pos_begin = begin(arr), pos_end = end(arr);
    while(pos_begin != pos_end){
	std::cout << *pos_begin++ << std::endl;
    }

    return 0;
}
