#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold; // unsigned units_sold = 0;  --> shouldn't have in-class initializer
    double revenue; //double revenue = 0;
};

int main(){
    Sales_data item = {"978-059xxxxx", 25, 15.99};  // "978xxxx"->bookNo, 25->units_sold, 15.99->revenue;
    return 0;}
