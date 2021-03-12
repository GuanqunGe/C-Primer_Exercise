#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &s, double d): bookNo(s), price(d){}

    virtual ~Quote() = default;

    //define move operation
    Quote(Quote &&) = default; //use the synthesized version
    Quote& operator=(Quote &&) = default;

    /*Quote(Quote &&q): bookNo(std::move(q.bookNo)), price(std::move(q.price)){
	q.bookNo = ""; q.price = 0.0;
    }

    Quote& operator=(Quote &&q){
	bookNo = std::move(q.bookNo);
	price = std::move(q.price);
	q.bookNo = ""; q.price = 0.0;
	return *this;
    }
    */

    // if I explicitly define move operation, I need to explicitly define copy operation as well, 
    // otherwise they will be deleted function
    Quote(const Quote &) = default;
    Quote& operator=(const Quote&) = default;

    std::string isbn() const {return bookNo; }
    virtual double net_price(std::size_t n) const {return n * price; }
    virtual std::ostream &debug(std::ostream &os) const{
	os << "ISBN: " << bookNo << " price: " << price;
	return os;
    }

    virtual Quote* clone() const &;
    virtual Quote* clone() &&;
    // I think this will work as well, and if I write function in this way, 
    // it does not need to be a member function 
    //virtual Quote* clone(const Quote&);
    //virtual Quote* clone(Quote &&);
protected:
    double price = 0.0;
private:
    std::string bookNo;
};

Quote* Quote::clone() const &{
    return new Quote(*this);
}

Quote* Quote::clone() &&{
    return new Quote(std::move(*this));
}

double print_total(std::ostream &os, const Quote &q, std::size_t n){
    double total_price = q.net_price(n);
    os << "ISBN: " << q.isbn() << " price: " << total_price << "\n";
    return total_price;
}
/*
Quote* Quote::clone(const Quote &q){
    return new Quote(q);
}

Quote* Quote::clone(Quote &&q){
    return new Quote(std::move(q));
}
*/
#endif
