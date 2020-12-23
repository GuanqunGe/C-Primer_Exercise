#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(){

    vector<int> grades{90, 97, 76, 89, 34, 60, 52, 63};

    //print each grade is high pass, pass, low pass, or fail
    //method 1, use conditional operator
    for(const auto &grade: grades){
        string status = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
        cout << grade << ": " << status << endl;
    }


    //method 2, if statement
    for(const auto &grade :grades){
        if(grade > 90) cout << grade << ": high pass" << endl;
        else if(grade > 75) cout << grade << ": pass" << endl;
        else if(grade >= 60) cout << grade << ": low pass" << endl;
        else cout << grade << ": fail " << endl;
    }

    return 0;
}
