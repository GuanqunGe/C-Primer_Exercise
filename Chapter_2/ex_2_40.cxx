#include <iostream>  //to use std::string

struct Sales_data{
     std::string bookNo;
     //in-class initlization using '=' and {}
     unsigned int units_sold={0};
     double revenue= {0};

     //in-class initialization using {}
     unsigned int units_sold{0};
     double revenue{0};

     //wrong, in-class initialization can't use ()
     unsigned int units_sold(0);
     double revenue(0);

};

int main(){
    return 0;
}
