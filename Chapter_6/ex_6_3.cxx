#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
long int fact(int num){

    //check if num is legal
    if(num <= 0){
	cerr << "argument can't be negative or zero: " << num << endl;
        return -1;
    }

    long int result = 1;  //was hoping long int would allow me to do factorial with more numbers, but it's still not large enough.

    //calculate the factorial
    do{
	result *= num--;
    }while(num > 1);

    return result;
}

int main(){
    int val;
    cout << "Please enter an number:";
    cin >> val;

    //print out
    //if val is not legal, the messages in function fact will be printed out first, then it's this line.
    //which makes sense, since the buffer will only be printed out when 'endl' is seen or the program ends.
    long int res = fact(val);
    cout << "Factorial of " << val << " is: " << res<< endl;
    return 0;
}
