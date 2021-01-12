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

    //constructor
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s){}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &is);

    //member functions
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
};
//declare interface function
istream &read(istream&, Sales_data &);
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

//define constructor
Sales_data::Sales_data(istream &is){
    read(is, *this);
}

//define member function 'combine' of class 'Sales_data'
Sales_data& Sales_data::combine(const Sales_data &rhs){
    if(isbn() == rhs.isbn()){
	units_sold += rhs.units_sold;
    	revenue += rhs.revenue;
    }
    return *this;
}

//define interface functions
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

    Sales_data total(cin);
    if(cin){  //if reading input for object 'total' is successful.
        Sales_data trans(cin);
        while(cin){  //if successfully read trans.
	//while(Sales_data trans(cin)){ //Wrong, because this constructor doesn't return anything,can't be used as an expression
	    if(trans.isbn() == total.isbn()){
		total.combine(trans);
	    }
	    else{
		print(cout, total) << endl;		
	        total = trans;   
	    }
            read(cin, trans); //read the next transaction
 	}

	//do not forget to print out what's remaining in total after while loop terminates
 	print(cout, total) << endl;
    }else{
	std::cerr << "No data?!" << std::endl;
    }

    return 0;
}
