#include <iostream>
#include <string>
class Bulk_quote;

class Quote{
public:
    Quote() = default;
   
    //both constructors work
    //Quote(const Quote &q):bookNo(q.bookNo), price(q.price){}
    Quote(const Bulk_quote &b);

    Quote(const std::string &book, double sales_price):
	bookNo(book), price(sales_price){}

    std::string isbn() const {return bookNo;}

    //double net_price(std::size_t n) const {return n * price; }
    virtual double net_price(std::size_t n) const {return n * price; }

    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
     double price = 0.0;
};

class Bulk_quote: public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double inprice, std::size_t qty, double indis):
	Quote(book, inprice), min_qty(qty), discount(indis) {}

    //double net_price(std::size_t n) const;
    double net_price(std::size_t n) const override;
    // define same function (same name, return type, parameter type) in both base class and derived class without 'virtual' keyword
    // does not cause compilation error. However calling the function through reference or pointer may yield results not as expected
    // calling this function through reference or pointer of base class type will call the version defined in base class
    // calling this function through object of derived class will call the version defined in derived class

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const{
    if( n >= min_qty) 
	return n * price * (1 - discount);
    else return n * price;
}

Quote::Quote(const Bulk_quote &b): bookNo(b.bookNo), price(b.price) {}


double print_total(std::ostream &os, const Quote &item, std::size_t n){
    double ret = item.net_price(n); 
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main(){
    Quote q("Harry", 80);
    print_total(std::cout, q, 5);

    Bulk_quote b;
    print_total(std::cout, b ,10);

    Bulk_quote b1("CPP",  60, 30, 0.4);
    print_total(std::cout, b1, 20);
    print_total(std::cout, b1, 40);
    std::cout << b1.net_price(40) << std::endl;

    Quote q1(b1);  //even though Bulk_quote doesn't have access to private member of Quote
		   //copy constructor, assignment operator still works
		   //wonder why reference to both the base-object part of derived object and the derived object has access to the private 
		   //members of base class within the class definition
    print_total(std::cout, q1, 3);
    return 0;
}
