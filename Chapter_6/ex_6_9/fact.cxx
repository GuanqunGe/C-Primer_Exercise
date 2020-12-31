#include "../include/Chapter6.h"

long int fact(int num){
    if(num <= 0){
        cerr << "argument can't be negative or zero: " << num << endl;
        return -1;
    }

    long int result = 1; 
    do{
        result *= num--;
    }while(num > 1);

    return result;

}
