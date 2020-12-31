#include "swap.h"

void swap(int &r1, int &r2){

    int temp_value = r1;
    r1 = r2;
    r2 = temp_value;
}
