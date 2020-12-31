#include "swap.h"

void swap(int *p1, int *p2){
 
    int temp_value = *p1;
    *p1 = *p2;  //dereference the pointer to get the object
    *p2 = temp_value;

    return ;
}
