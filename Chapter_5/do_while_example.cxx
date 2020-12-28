#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){
 
    string rsp;
    do{
	cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
	cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2 << " = " << val1+val2 <<"\n\n" << "More? Enter yes or no: ";
        cin >> rsp;  //cin >> ignores the leading whitespaces. 

	//cout << "rsp is : " << rsp << endl;  //if we hit end-of-file, rsp will be an empty string; if we type "yes" then hit end-of-file, rsp will be "yes", and the loop will continue on. 

    }while (!rsp.empty() && rsp[0] != 'n');  //this loop does not rely on the status of cin, instead, it only relys on what's in rsp. 

    return 0;
}
