#include <iostream>

using std::cout;
using std::endl;

int main(){

    //expect 91
    cout << "12/3*4 + 5*15 + 24%2/2 = " << 12/3*4+5*15+24%4/2 << endl;
    //expect -86
    cout << "-30*3 + 21/5 = " << -30*3+21/5 << endl;
    //expect -18
    cout << "-30 + 3*21/5 = " << -30+ 3*21/5 << endl;
    //expect 0
    cout << "30/3*21%5  = " << 30/3*21%5 << endl;
    //expect -2
    cout << "-30/3*21%4 = " << -30/3*21%4 << endl;


    return 0;
}
