#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv){

    if(argc < 2){
	std::cerr << "Need extra argument: filename " << std::endl;
	return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
	std::cerr << "Fail to open file: " << argv[1] << std::endl;
    }

    std::vector<Sales_data> transactions;
    for(Sales_data tran; read(infile, tran); transactions.push_back(tran)) {}

    std::cout << "Before Sorting \n" << std::endl;
    // both print and std::cout are defined outside the main program, so we don't need to pass it in the capture list
    std::for_each(transactions.cbegin(), transactions.cend(), [](const Sales_data &S1) { print(std::cout, S1) << std::endl; } );

    std::sort(transactions.begin(), transactions.end(), [](const Sales_data &S1, const Sales_data &S2){return S1.isbn() < S2.isbn(); });

    std::cout << "After Sorting \n" << std::endl;
    std::for_each(transactions.cbegin(), transactions.cend(), [](const Sales_data &S1) { print(std::cout, S1) << std::endl; } );

    return 0;
}
