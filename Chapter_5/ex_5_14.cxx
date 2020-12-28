#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){
    //to save current string being read, previous string read, and the one with largest frequency
    string current_string, previous_string, frequentist_string;
    unsigned frequency=0, largest_frequency = 0;

    cout << "Please enter a list of strings.. " << endl;
    while(cin >> current_string){
 	if(current_string != previous_string){

            //update the largest frequency and frequentist strings if needed
	    if(frequency > largest_frequency){
            	largest_frequency = frequency;
            	frequentist_string = previous_string;
            }

            //update previous string before moving on to a new readout
            previous_string = current_string;
	    frequency = 1;

	}else ++frequency;

    }

    //update for the last repeated word, if needed
    if(frequency > largest_frequency){
        largest_frequency = frequency;
	frequentist_string = previous_string;
    }

   if(largest_frequency > 1) cout << "The word " << frequentist_string << " has been repeated for " << largest_frequency << " times"<< endl;
   else cout << "No word has been repeated so far" << endl;

   return 0;
}
