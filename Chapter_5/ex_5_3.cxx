#include <iostream>

using std::cout;
using std::endl;

int main(){

    int sum =0, val = 0;

    while(val <= 10){
        sum += val;
	++val;
    }
    cout << "Sum is "<< sum << endl;


    //different way to calculate the sum
    sum = val = 0;
    while(val <=10 ) sum += val++;  //postfix increment has higher precedence than +=
    cout << "Sum is "<< sum << endl;

    //third way to do this
    sum = val =0;
    while(val <=10 ) sum += val, ++val;  //comma operator, the whole thing is 1 statment.
    cout << "Sum is " << sum << endl;
    return 0;
    

}
