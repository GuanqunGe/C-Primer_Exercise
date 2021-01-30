/*
 * this file is copied from and expanded on Chapter_7/ex_7_14.cxx
 */
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;


struct Sales_data;
// interface function that uses class should be declared/defined after the class declaration
istream &read(istream&, Sales_data &);  //declare read function before the Sales_data constructor
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

struct Sales_data{
    //members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    //constructor
    //Sales_data() = default;
    Sales_data():bookNo(""), units_sold(0), revenue(0){}
    Sales_data(const string &s):bookNo(s){}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &is){ read(is, *this); }

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
#endif
