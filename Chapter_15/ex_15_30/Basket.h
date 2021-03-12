#ifndef BASKET_H
#define BASKET_H

#include "Quote.h"
#include "Derived.h"
#include <set>
#include <memory>

class Basket{
public:
    //Basket() = default;
 
    void add_item(const Quote&);
    void add_item(Quote&&);

    double total_receipt(std::ostream &) const;
private:

    // 1. static function can't be defined as const.
    // 2. turns out we need to define the operation before using it to define the multiset
    // otherwise during compilation we will get an error saying
    // "undefined reference to `Basket::compare(std::shared_ptr<Quote> const&, std::shared_ptr<Quote> const&)"
    static bool compare(const std::shared_ptr<Quote> &lhs,
			const std::shared_ptr<Quote> &rhs){
	return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) * > items{compare};
};

//inline
//bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs){
//    return lhs->isbn() < rhs->isbn();
//}

void Basket::add_item(const Quote &q){

    //directly use reference q to create object in the heap, but this is limited to create Quote object only, not the derived object
    //items.insert(std::make_shared<Quote>(q));

  
    //use virtual clone() function
    items.insert(std::shared_ptr<Quote>(q.clone()));
}

void Basket::add_item(Quote &&q){
    items.insert(std::shared_ptr<Quote>(std::move(q).clone()));
}

double Basket::total_receipt(std::ostream &os) const{

    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); 
	iter = items.upper_bound(*iter)){

  	sum += print_total(os, **iter, items.count(*iter));
	//sum += **iter.net_price( items.count(*iter));
	//os << **iter.isbn() << " " << **iter.net_price( items.count(*iter)) << std::endl;
    }

    //push the buffer
    os << "Sum: " << sum << std::endl;

    return sum;
}
#endif
