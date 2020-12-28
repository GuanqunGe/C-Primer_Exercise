#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

// compare two vectors, vec1 should have larger/same number of elements than vec2
bool IsPrefix(vector<int> &vec1, vector<int> &vec2){

    bool is_prefix = true;
    for(decltype(vec2.size()) i =0; i != vec2.size(); ++i){
        if(vec2[i] != vec1[i]){
	    is_prefix = false;
	    break;  //once find a different element, jump out of the loop, to save time
        }
    }

    return is_prefix;
}

int main(){

    //now, I have a question of not knowing how to get two vectors from the keyboard input...
    vector<int> int_vec1 = {0, 1, 2, 3, 4, 5, 6}, int_vec2 = {0, 1,2 ,3 ,4 ,5 ,7};

    decltype(int_vec1.size()) vec1_size = int_vec1.size(), vec2_size = int_vec2.size();
    //depending on their sizes, call the IsPrefix function
    bool is_prefix = vec1_size >= vec2_size ? IsPrefix(int_vec1, int_vec2) : IsPrefix(int_vec2, int_vec1);

    // true or false will be printed as 1 or 0, in std::cout, so need to convert it to strings "true" or "false" accordingly.
    cout << "One vector is the prefix of the other one? " << (is_prefix ? "true" : "false")  << endl;


    return 0;

}

