#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;


struct Sales_data;
// interface function that uses class should be declared/defined after the class declaration
istream &read(istream&, Sales_data &);  //declare read function before the Sales_data constructor
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

struct Sales_data{
    private:
    //members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    public:
    //constructor
    //Sales_data() = default;
    Sales_data(): Sales_data("", 0, 0.0){ std::cout << "Default constructor" << std::endl;}
    Sales_data(const string &s): Sales_data(s, 0, 0.0){std::cout << "one string parameter contructor" << std::endl;}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){
 	std::cout << "3 parameter constructor" << std::endl; }
    Sales_data(istream &is): Sales_data(){ 
	std::cout << "istream constructor" << std::endl;
	read(is, *this); }

    //member functions
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

    friend istream &read(istream&, Sales_data &);  
    friend ostream &print(ostream&, const Sales_data&);
};

//define member function 'combine' of class 'Sales_data'
Sales_data& Sales_data::combine(const Sales_data &rhs){
    if(isbn() == rhs.isbn()){
	units_sold += rhs.units_sold;
    	revenue += rhs.revenue;
    }
    return *this;
}

//define interface functions
istream &read(istream &ins, Sales_data &inclass){
    double unit_price = 0;
    ins >> inclass.bookNo >> inclass.units_sold >> unit_price;
    inclass.revenue = unit_price * inclass.units_sold;
    return ins;
}

ostream &print(ostream &outs, const Sales_data &inclass){

    outs << inclass.bookNo << " " << inclass.units_sold 
         << " " << inclass.revenue << " ";
    return outs;
}

Sales_data add(const Sales_data &inc1, const Sales_data &inc2){
 
    Sales_data out = inc1;
    out.combine(inc2);
    return out;
}



int main(){
    std::cout << "A: " << std::endl;
    Sales_data A; 
    std::cout << "B:  " << std::endl;
    Sales_data B("Harry");
    std::cout << "C: " << std::endl;
    Sales_data C("Harry Potter-Half Blood Prince", 5, 89.3);
    std::cout << "D: " << std::endl;
    Sales_data D(cin);
    std::cout << "E: " <<  std::endl;
    Sales_data E = add(B, D);

    print(std::cout, A) << std::endl;
    print(std::cout, B) << std::endl;
    print(std::cout, C) << std::endl;
    print(std::cout, D) << std::endl;   
    print(std::cout, E) << std::endl;
    return 0;
}
