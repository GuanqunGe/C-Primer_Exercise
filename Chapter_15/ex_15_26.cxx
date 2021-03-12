#include <iostream>
#include <string>

class Quote{
public:
    Quote():bookNo(""), price(0.0){std::cout << "Quote::Quote()" << std::endl; }
    Quote(const std::string &s, double p): bookNo(s), price(p){
	std::cout << "Quote::Quote(const std::string&, double)" << std::endl; 
    }

    //copuy-control members
    Quote(const Quote &q): bookNo(q.bookNo), price(q.price){
	std::cout << "Quote(const Quote&)" << std::endl;
    }

    Quote(Quote &&q):bookNo(std::move(q.bookNo)), price(std::move(q.price)){
	 q.price = 0; q.bookNo = "";
	std::cout << "Quote(Quote &&) " << std::endl;
    }

    Quote& operator=(const Quote &q){
	bookNo = q.bookNo;
	price = q.price;
	std::cout << "Quote& operator=(const Quote&)" << std::endl; 
	return *this;
    }

    Quote& operator=(Quote &&q){
	bookNo = std::move(q.bookNo);
	price = std::move(q.price);
	q.price = 0; q.bookNo = "";
	std::cout << "Quote& operator=(Quote&&)" << std::endl;
	return *this;
    }

    virtual ~Quote(){
	std::cout << "Quote::~Quote()"<< std::endl;
    }

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
    Disc_quote():Quote(){std::cout << "Disc_quote::Disc_quote() " << std::endl; }
    Disc_quote(const std::string &s, double p, std::size_t q, double d):
	Quote(s, p), quantity(q), discount(d){
	std::cout << "Disc_quote::Disc_quote(const std::string&, double, std::size_t, double)"<< std::endl;
    }

    //copy control members
    Disc_quote(const Disc_quote &d):Quote(d), quantity(d.quantity),discount(d.discount){
	std::cout << "Disc_quote::Disc_quote(const Disc_quote&)" << std::endl;
    }

    Disc_quote(Disc_quote &&d): Quote(std::move(d)),quantity(std::move(d.quantity)), discount(std::move(d.discount)){
	d.quantity = 0; d.discount = 0.0;
	std::cout << "Disc_quote::Disc_quote(Disc_quote &&)" << std::endl;
    }

    Disc_quote &operator=(const Disc_quote &d){
	Quote::operator=(d);
 	quantity = d.quantity;
	discount = d.discount;
	std::cout << "Disc_quote::operator=(const Disc_quote &)" << std::endl;
	return *this;
    }

    Disc_quote& operator=(Disc_quote &&d){
	Quote::operator=(std::move(d));
	quantity  = std::move(d.quantity);
	discount = std::move(d.discount);
	d.quantity = 0; d.discount = 0.0;
	std::cout << "Disc_quote::operator-(Disc_quote&)" << std::endl;
	return *this;
    }

    ~Disc_quote(){
	std::cout << "Disc_quote::~Disc_quote()" << std::endl;
    }

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
    Bulk_quote(){std::cout << "Bulk_quote::Bulk_quote()" << std::endl; }

    using Disc_quote::Disc_quote; //inherits constructor from Disc_quote

//    Bulk_quote(const std::string &s, double p, std::size_t q, double d):
//	Disc_quote(s, p, q, d){
//	std::cout << "Bulk_quote::Bulk_quote(const string&, double, size_t, double)" << std::endl;
//    }

    //copy-control members
    Bulk_quote(const Bulk_quote &b): Disc_quote(b){
	std::cout << "Bulk_quote::Bulk_quote(const Bulk_quote &) " << std::endl;
    }

    Bulk_quote(Bulk_quote &&b): Disc_quote(std::move(b)){
	std::cout << "Bulk_quote::Bulk_quote(Bulk_quote &&)" << std::endl;
    }

    Bulk_quote &operator=(const Bulk_quote &b){
	Disc_quote::operator=(b);
	std::cout << "Bulk_quote::operator=(const Bulk_quote&)" << std::endl;
	return *this;
    }

    Bulk_quote &operator=(Bulk_quote &&b){
	Disc_quote::operator=(std::move(b));
	std::cout << "Bulk_quote::operator=(Bulk_quote &&)" << std::endl;
	return *this;
    }

    ~Bulk_quote(){
	std::cout << "Bulk_quote::~Bulk_quote()" << std::endl;
    }

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

    //Disc_quote d;
    Bulk_quote b1 = b;
    {
        Bulk_quote b2  = std::move(b);
	b1 = std::move(b2);
    }

    print_total(std::cout, q, 6) << std::endl;
    print_total(std::cout, b, 6) << std::endl;
    return 0;
}
