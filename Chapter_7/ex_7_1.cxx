#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(){

    Sales_data total;
    double unit_price;
    if(cin >> total.bookNo >> total.units_sold >> unit_price){
	total.revenue = unit_price * total.units_sold;
        Sales_data trans;
	while(cin >> trans.bookNo >> trans.units_sold >> unit_price){
	    trans.revenue = trans.units_sold * unit_price;
	    if(trans.bookNo == total.bookNo){
		total.units_sold += trans.units_sold;
	 	total.revenue += trans.revenue;
	    }
	    else{
		cout << "ISBN: " << total.bookNo << ", units sold: " << total.units_sold << ", total price: " << total.revenue << ", average price: " << total.revenue/total.units_sold << endl;
	        //total = trans;   //OK, don't need to define assignment
	        total.bookNo = trans.bookNo;
		total.units_sold = trans.units_sold;
		total.revenue = trans.revenue;
	    }
 	}

	//do not forget to print out what's remaining in total after while loop terminates
        cout << "ISBN: " << total.bookNo << ", units sold: " << total.units_sold << ", total price: " << total.revenue << ", average price: " << total.revenue/total.units_sold <<
 endl;
    }else{
	std::cerr << "No data?!" << std::endl;
    }

    return 0;
}
