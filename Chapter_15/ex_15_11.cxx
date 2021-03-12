#include <iostream>
#include <string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
	bookNo(book), price(sales_price){}

    std::string isbn() const {return bookNo;}

    virtual double net_price(std::size_t n) const {return n * price; }
    virtual std::ostream &debug( std::ostream &os) const { os << bookNo << " " << price << " "; return os; }
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

    double net_price(std::size_t n) const override;
    std::ostream &debug(std::ostream &) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const{
    if( n >= min_qty) 
	return n * price * (1 - discount);
    else return n * price;
}

std::ostream &Bulk_quote::debug(std::ostream &os) const{
    this->Quote::debug(os);
    os << min_qty << " " << discount;
    return os;
}

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

    q.debug(std::cout) << std::endl;
    b.debug(std::cout) << std::endl;
    b1.debug(std::cout) << std::endl;

    Quote *pq = &b1;
    pq->debug(std::cout) << std::endl;
    return 0;
}
