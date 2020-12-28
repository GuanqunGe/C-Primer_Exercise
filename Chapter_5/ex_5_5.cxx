#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(){

    //create and enter a vector of grades
    vector<int> grades;
    int grade;   //should use unsigned int
    cout << "Please enter a few grades" << endl;
    while(cin >> grade) grades.push_back(grade);

 
    //generate the letter grade
    for(const auto &e : grades){
        if(e <0 || e > 100){
	    cout << e << " is not a valid score.." << endl;
	    continue;
	}
	string lettergrade;
        if(e < 60) lettergrade = "F";
        else if(e < 70) lettergrade = "D";
        else if(e < 80) lettergrade = "C";
        else if(e < 90) lettergrade = "B";
        else if(e < 100) lettergrade = "A";
        else if(e == 100) lettergrade = "A++";

        if(e >= 60 && e%10 >7) lettergrade += "+";
        else if(e >= 60 && e!= 100 && e%10 < 3) lettergrade += "-";

        cout << e << ": " << lettergrade << endl;
    }

    return 0;
}
