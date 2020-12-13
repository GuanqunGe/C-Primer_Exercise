#include <iostream>
#include <string>
#include "include/Sales_data.h"

int main(){
    Sales_data total_sale;
    double price;
    std::cout << "Please enter the sale information" << std::endl;

    if(std::cin >> total_sale.bookNo >> total_sale.units_sold >> price){
        total_sale.revenue = total_sale.units_sold * price;

        Sales_data current_sale;
        while(std::cin >> current_sale.bookNo >> current_sale.units_sold >> price){
           if(current_sale.bookNo == total_sale.bookNo){
                total_sale.units_sold += current_sale.units_sold;
                total_sale.revenue += current_sale.units_sold * price;
           }
           else{
                std::cout << "Book No: " << total_sale.bookNo << ", units sold: "<< total_sale.units_sold << std::endl;
                total_sale.bookNo = current_sale.bookNo;
                total_sale.units_sold = current_sale.units_sold;
                total_sale.revenue = total_sale.units_sold * price;
           }
        }

        std::cout << "Book No: " << total_sale.bookNo << ", units sold: " << total_sale.units_sold << std::endl;
        return 0;
    }
    else{
        std::cerr << "No data entered" << std::endl;
        return -1;
    }

}
