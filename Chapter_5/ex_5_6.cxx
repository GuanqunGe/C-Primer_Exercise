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
    int grade;
    cout << "Please enter a few grades" << endl;
    while(cin >> grade) grades.push_back(grade);

 
    //generate the letter grade
    for(const auto &e : grades){
        if(e <0 || e > 100){
	    cout << e << " is not a valid score.." << endl;
	    continue;
	}
	string lettergrade;

        lettergrade = (e < 60)?"F":(e < 70) ? "D": (e < 80) ? "C": (e <90) ?"B":(e<100)? "A":"A++";

        if(e >= 60 && e%10 >7) lettergrade += "+";
        else if(e >= 60 && e!= 100 && e%10 < 3) lettergrade += "-";

        cout << e << ": " << lettergrade << endl;
    }

    return 0;
}
