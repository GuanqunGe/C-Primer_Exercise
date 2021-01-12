#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

struct Sales_data{
    //members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    //member functions
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
};


//define member function 'combine' of class 'Sales_data'
Sales_data& Sales_data::combine(const Sales_data &rhs){
    if(isbn() == rhs.isbn()){
	units_sold += rhs.units_sold;
    	revenue += rhs.revenue;
    }
    return *this;
}

//define interface functions
// interface function that uses class should be declared/defined after the class declaration
istream &read(istream &ins, Sales_data &inclass){
    double unit_price = 0;
    ins >> inclass.bookNo >> inclass.units_sold >> unit_price;
    inclass.revenue = unit_price * inclass.units_sold;
    return ins;
}

ostream &print(ostream &outs, const Sales_data &inclass){

    outs << inclass.bookNo << " " << inclass.units_sold 
         << " " << inclass.revenue << " ";
    return outs;
}

Sales_data add(const Sales_data &inc1, const Sales_data &inc2){
 
    Sales_data out = inc1;
    out.combine(inc2);
    return out;
}



int main(){

    Sales_data total;
    double unit_price;
    if(read(cin, total)){
        Sales_data trans;
	while( read(cin, trans)){
	    if(trans.isbn() == total.isbn()){
		total.combine(trans);
	    }
	    else{
		print(cout, total) << endl;		
	        //total = trans;   //OK, don't need to define assignment
	        total.bookNo = trans.bookNo;
		total.units_sold = trans.units_sold;
		total.revenue = trans.revenue;
	    }
 	}

	//do not forget to print out what's remaining in total after while loop terminates
 	print(cout, total) << endl;
    }else{
	std::cerr << "No data?!" << std::endl;
    }

    return 0;
}
