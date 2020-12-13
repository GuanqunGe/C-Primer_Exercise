#include <iostream>
#include <string>

//define Sales_data structure
struct Sales_data{
    std::string bookNo;
    unsigned units_sold{0};   // units sold can't be negative
    double revenue{0};
};


//rewrite ex 1.20
int main(){

    Sales_data sale;
    double price ; // price of each transaction
    std::cout << "Please type in the sales items" << std::endl;
    while(std::cin >> sale.bookNo >> sale.units_sold >> price){
    	sale.revenue = sale.units_sold*price;
    	std::cout << "Book sold:"<< sale.bookNo << ", units sold:" << sale.units_sold<< ", total price: " << sale.revenue << ", average price: " << price << std::endl;
    }
    return 0;
}


//rewrite ex 1.21
int main(){
    Sales_data sale1, sale2;
    double price;
    std::cout << "Please enter the sales information"<< std::endl;
    std::cin >> sale1.bookNo >> sale1.units_sold >> price;
    sale1.revenue = sale1.units_sold*price;
    std::cin >> sale2.bookNo >> sale2.units_sold >> price;
    sale2.revenue = sale2.units_sold*price;
    if(sale1.bookNo == sale2.bookNo){
	unsigned total_units = sale1.units_sold + sale2.units_sold;
	if(total_units != 0){
	     std::cout << "Book sold: "<< sale1.bookNo << ", units sold:" << total_units << ", total price:" << sale1.revenue + sale2.revenue <<", average price: " << (sale1.revenue + sale2.revenue)/total_units << std::endl; 
	}else   std::cout << "No book sold" << std::endl;
	return 0;
    }
    else{
	 std::cerr << "Book ISBN is different: " << sale1.bookNo << " " << sale2.bookNo << std::endl;
	 return -1;
    }
}


//rewrite ex 1.22
int main(){
     Sales_data total_sale;
     double price;
     std::cout << "Please enter the sale information" << std::endl;

     //read the first sales_data into the sum
     if(std::cin >> total_sale.bookNo >> total_sale.units_sold >> price){
	total_sale.revenue = total_sale.units_sold * price;

	//read succesive individual sale info
	Sales_data current_sale;
        while(std::cin >> current_sale.bookNo >> current_sale.units_sold >> price){
	    //if it's not the same book, skip it
	    if(current_sale.bookNo != total_sale.bookNo){
		std::cout << "Book ISBN is different, ignore this one" << std::endl;
		continue;
	    }

	    //add units, price to the sum
	    total_sale.units_sold += current_sale.units_sold;
            total_sale.revenue += current_sale.units_sold * price;
	}

        if(total_sale.units_sold != 0){
	    std::cout << "Book ISBN: " << total_sale.bookNo << ", units sold: " << total_sale.units_sold << ", total price: " << total_sale.revenue << ", average price: " << total_sale.revenue/total_sale.units_sold << std::endl;
  	}else std::cout << "No book sold" << std::endl;
	
     }else{
	std::cout << "No book info entered" << std::endl;
     }

     return 0;
}



//rewrite ex 1.23
int main(){
    Sales_data total_sale;
    double price;
    std::cout << "Please enter the sale information" << std::endl;
 
    if(std::cin >> total_sale.bookNo >> total_sale.units_sold >> price){
        total_sale.revenue = total_sale.units_sold * price;

	//read current sale object
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

    return 0;
}
