#include <iostream>
#include <string>
#include "Quote.h"
#include "Derived.h"
#include "Basket.h"

int main(){

    Basket shopbag;
    
    //book shelf
    Quote q("AAAA", 50);
    Bulk_quote b("BBBB", 60, 5, 0.25);
    Promotion_quote p("CCCC", 100, 2, 0.2);

    //add books
    shopbag.add_item(q); // 2 copies of q - $100
    shopbag.add_item(q);
    shopbag.add_item(b); // 6 copies of b - $270
    shopbag.add_item(b);
    shopbag.add_item(b);
    shopbag.add_item(b);
    shopbag.add_item(b);
    shopbag.add_item(b);
    shopbag.add_item(p); // 3 copies of p - $260
    shopbag.add_item(p);
    shopbag.add_item(p);
    shopbag.add_item(Bulk_quote("DDDD", 80, 3, 0.4)); // 2 copies of temp object - $160
    shopbag.add_item(Bulk_quote("DDDD", 80, 3, 0.4));

    shopbag.total_receipt(std::cout); //expect total: $790

    return 0;
}
