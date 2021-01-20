#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Date{
    unsigned year;
    unsigned month;
    unsigned day;

    // define as static members, to avoid having these members for each Date class.
    static vector<string> full_month;
    static vector<string> abbr_month;
    static vector<string> num_month;

    // private implementation function, replace substr
    string &replace_vecstr( string &, const vector<string> &, const vector<string> &);
    string &replace_substr( string &, const string &, const string &);

public:
    //default constructor
    Date(): year(0), month(0), day(0){}
    Date( const string &);

    // print the date in uniform format
    void Print() const { std::cout << "Date: "<< month << "/" << day << "/" << year << std::endl; }
};

//definition of static members
vector<string> Date::full_month{"January", "February", "March", "April", "May", "June",
			      "July", "Auguest", "September", "October", "November", "December"};
vector<string> Date::abbr_month{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct",
				"Nov", "Dec"};
vector<string> Date::num_month{"1", "2", "3", "4", "5", "6", "7", "8", "9","10", "11", "12"};

//replace every instance of s1 in s by s2
string &Date::replace_substr( string &s, const string &s1, const string &s2){
 
    decltype(s.size()) pos = 0;
    while( (pos = s.find(s1, pos)) != string::npos){
	s.replace(pos, s1.size(), s2);
	pos += s2.size();
    }
}

// replace every instance of element in vec1 in string s by corresponding ones in vec2
string &Date::replace_vecstr( string &s, const vector<string> &vec1, const vector<string> &vec2){

    if(vec1.size() != vec2.size()){
	std::cerr << "Two replacement vectors have different size: vec1: "<< vec1.size() << ", vec2: " << vec2.size() << std::endl;
	return s;
    }

    for(decltype(vec1.size()) i = 0; i != vec1.size(); ++i){
	replace_substr(s, vec1[i], vec2[i]);
    }
}

Date::Date(const string &s): Date() {
    string s_copy(s);
    //substitue its wordy month notation to numbers
    replace_vecstr(s_copy, full_month, num_month);
    replace_vecstr(s_copy, abbr_month, num_month);

    //now s_copy is in good state
    string month_str{"1234567890"};
    decltype(s.size()) order = 0, pos = 0;
    while( (pos = s_copy.find_first_of(month_str, pos)) != string::npos){
        s_copy = s_copy.substr(pos);

        // everytime std::stoi happens, update the pos to be the next nonnumeric characters
   	if(order == 0) month = std::stoi(s_copy, &pos);
    	else if(order == 1) day = std::stoi(s_copy, &pos);
    	else if(order == 2) year = std::stoi(s_copy, &pos);
    	++order;
    }

    if(order != 3){
	 std::cerr << "Format is not right, please examine your format: ";
	 std::cerr << "please follow month day year format " << std::endl;
    }
}

 
int main(){

    Date A;
    A.Print();

    Date B("January, 13, 1990");
    B.Print();

    Date C("01/13/1990");
    C.Print();

    Date D("Jan 13, 1990");
    D.Print();

    Date E("Jan., 13, 1990");
    E.Print();

    Date F("Ja, 13, 1990");
    F.Print();

    return 0;
}
