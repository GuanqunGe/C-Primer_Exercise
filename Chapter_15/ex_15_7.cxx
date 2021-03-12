#include <iostream>
#include <string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
	bookNo(book), price(sales_price){}

    std::string isbn() const {return bookNo;}

    virtual double net_price(std::size_t n) const {return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
     double price = 0.0;
};

// promotion for bulk ordering
class Bulk_quote: public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double inprice, std::size_t qty, double indis):
	Quote(book, inprice), min_qty(qty), discount(indis) {}

    double net_price(std::size_t n) const override;
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const{
    if( n >= min_qty) 
	return n * price * (1 - discount);
    else return n * price;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n){
    double ret = item.net_price(n); 
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

// promotion for first few books
class Promotion: public Bulk_quote{
public:
    Promotion(const std::string &book, double inprice, std::size_t qty, double indis):
	Bulk_quote(book, inprice, qty, indis) {}

    double net_price(std::size_t n) const override;
};

double Promotion::net_price(std::size_t n) const{
    if( n > min_qty)
	return (n-min_qty) * price + min_qty * price * (1-discount);
    else
	return n * price * (1-discount);;
}


int main(){
    Quote q("Harry", 80);
    print_total(std::cout, q, 5);

    Bulk_quote b;
    print_total(std::cout, b ,10);

    Bulk_quote b1("CPP",  60, 30, 0.4);
    print_total(std::cout, b1, 20);
    print_total(std::cout, b1, 40);

    Promotion p("DUNE", 80, 3, 0.2);
    print_total(std::cout, p, 2);
    print_total(std::cout, p, 4);
    return 0;
}
