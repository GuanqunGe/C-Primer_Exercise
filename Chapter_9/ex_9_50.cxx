#include <iostream>
#include <vector>
#include <string>

double sum_vector(const std::vector<std::string> &vec){
//int sum_vector(const std::vector<std::string> &vec){

    double sum = 0; // int sum = 0;
    std::cout << "Sum of ";
    for(auto &s: vec){
	sum += std::stod(s);
	//sum += std::stoi(s);
	std::cout << s << " ";
    }
    std::cout << "is : " << sum << std::endl;
    return sum;
}

int main(){
    std::vector<std::string> str_vec{"1","76", "89", "90"},
			     d_vec{".5", "0.9", "3.1", "4.5", "7.5"};

    //sum_vector(str_vec);
    sum_vector(d_vec);
 
    return 0;
}
