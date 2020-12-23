#include <iostream>

using std::cout;
using std::endl;

int main(){
    int a=10, b =5, c=4, d =1;
    if(a>b && b>c && c>d)
	cout << "a > b > c > d"<< endl;
    else  cout << "Not a > b > c > d" << endl;

    return 0;
}
