#include <iostream>
#include <string>

class Quote{
public:
    Quote()=default;
    Quote(const std::string &s, double p): bookNo(s), price(p){}

    virtual ~Quote() = default;

    std::string isbn() const {return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }

    virtual std::ostream &debug(std::ostream &os) const{
	os << "ISBN: " << bookNo << " price: " << price;
	return os;
    }

protected:
    double price = 0.0;
private:
    std::string bookNo;
};

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &s, double p, std::size_t q, double d):
	Quote(s, p), quantity(q), discount(d){}

    double net_price(std::size_t n) const = 0; //pure virtual function
    std::ostream &debug(std::ostream &os) const override{
	this->Quote::debug(os) << " quantity: " << quantity << " discount: " << discount;
        return os;
    }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double p, std::size_t q, double d):
	Disc_quote(s, p, q, d){}

    double net_price(std::size_t n) const override;
};

double Bulk_quote::net_price(std::size_t n) const{
    if( n >= quantity) 
	return n * price * (1 - discount);
    else
	return n * price;
}

class Promotion : public Disc_quote{
public:
    Promotion() = default;
    Promotion(const std::string &s, double p, std::size_t q, double d):
	Disc_quote(s, p, q, d){}
 
    double net_price(std::size_t n) const override{
	if( n <= quantity)
	    return n * price * (1 - discount);
        else
	    return quantity * price * (1 - discount) + ( n - quantity) * price;
    }
};

std::ostream &print_total(std::ostream &os, const Quote &item, std::size_t n){
    double price = item.net_price(n);
    os << item.isbn() << " " << price;
    return os;
}

int main(){

    Quote q("CPP", 80);
    Bulk_quote b("CPP", 80, 5, 0.4);
    Promotion p("CPP", 80, 3, 0.4);

    //Disc_quote d;

    p.debug(std::cout) << std::endl;

    print_total(std::cout, q, 6) << std::endl;
    print_total(std::cout, b, 6) << std::endl;
    print_total(std::cout, p, 6) << std::endl;
    return 0;
}
