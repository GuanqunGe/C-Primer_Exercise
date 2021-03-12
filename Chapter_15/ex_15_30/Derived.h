#ifndef DERIVED_H
#define DERIVED_H

#include "Quote.h"
#include <iostream>
#include <string>

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &s, double p, std::size_t q, double d):
	Quote(s, p), quantity(q), discount(d) {}

    // no need to define copy-control members, as compiler will synthesize thse members
    // no need to define clone() function either, as Disc_quote is abstract class, there will be no object of this type.

    double net_price(std::size_t n) const = 0;
    std::ostream &debug(std::ostream &os) const override{
	Quote::debug(os) << " quantity: " << quantity << " discount: " << discount;
	return os;
    }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    using Disc_quote::Disc_quote; //inherit constructor from Disc_quote

    double net_price(std::size_t n ) const override{
	if( n >= quantity )
	    return n * price * (1 - discount);
        else
	    return n * price;
    }

    Bulk_quote* clone() const & override;
    Bulk_quote* clone() && override;
};

class Promotion_quote : public Disc_quote{
public:
    Promotion_quote() = default;
    using Disc_quote::Disc_quote;

    double net_price(std::size_t n) const override{
	if( n <= quantity)
	    return n * price * (1 - discount);
        else
	    return quantity*price*(1-discount) + (n - quantity)*price;
    }

    Promotion_quote* clone() const & override;
    Promotion_quote* clone() && override;
};

Bulk_quote* Bulk_quote::clone() const &{
    return new Bulk_quote(*this);
}

Bulk_quote* Bulk_quote::clone() &&{
    return new Bulk_quote(std::move(*this));
}

Promotion_quote* Promotion_quote::clone() const &{
    return new Promotion_quote(*this);
}

Promotion_quote* Promotion_quote::clone() && {
    return new Promotion_quote(std::move(*this));
}

#endif
