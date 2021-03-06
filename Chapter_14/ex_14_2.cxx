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
istream &read(istream&, Sales_data &);  
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

struct Sales_data{
    friend istream &read(istream&, Sales_data &);  
    friend ostream &print(ostream&, const Sales_data&);
    friend istream &operator>>(istream&, Sales_data&);
    friend ostream &operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data &);
    friend Sales_data operator-(const Sales_data&, const Sales_data &);
    private:
    //members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    public:
    //constructor
    //Sales_data() = default;
    Sales_data():bookNo(""), units_sold(0), revenue(0){}
    Sales_data(const string &s):bookNo(s){}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &is){ read(is, *this); }

    Sales_data &operator=(const std::string &);

    //member functions
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator-=(const Sales_data &);
};

//define member function 'combine' of class 'Sales_data'
Sales_data& Sales_data::combine(const Sales_data &rhs){
    if(isbn() == rhs.isbn()){
	units_sold += rhs.units_sold;
    	revenue += rhs.revenue;
    }
    return *this;
}

inline
double Sales_data::avg_price() const{
    if(units_sold) return revenue/units_sold;
    else return 0.;
}

Sales_data &Sales_data::operator=(const std::string &s){
    bookNo = s;
    units_sold = 0;
    revenue = 0.;
    return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &inclass){
    if(bookNo == inclass.isbn()){
	units_sold += inclass.units_sold;
   	revenue += inclass.revenue;
    }
    return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &inclass){
    if(bookNo == inclass.isbn() && units_sold > inclass.units_sold){
	units_sold -= inclass.units_sold;
        revenue -= inclass.revenue;
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


istream &operator>>(istream &is, Sales_data &inc){
    double unit_price;
    is >> inc.bookNo >> inc.units_sold >> unit_price;
    if(is)
	inc.revenue = inc.units_sold * unit_price;
    else
        inc = Sales_data();
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &inc){
    os << inc.bookNo << " " << inc.units_sold << " " << inc.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &inc1, const Sales_data &inc2){
    Sales_data result = inc1;
    result += inc2;
    return result;
}

Sales_data operator-(const Sales_data &inc1, const Sales_data &inc2){
    Sales_data result = inc1;
    result -= inc2;
    return result;
}

Sales_data add(const Sales_data &inc1, const Sales_data &inc2){
 
    Sales_data out = inc1;
    out.combine(inc2);
    return out;
}



int main(){
    Sales_data A;
    Sales_data B("Harry");
    Sales_data C("Harry Potter-Half Blood Prince", 5, 89.3);
    Sales_data D(cin);
    Sales_data E;
    std::cin >> E;
    std::cout << (std::cin.good() ? "good": "bad") << std::endl; 

    print(std::cout, A) << std::endl;
    std::cout << A << std::endl;
    print(std::cout, B) << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    std::cout << D << std::endl;   
    std::cout << E << std::endl;
    std::cout << D + E << std::endl;
    std::cout << D - E << std::endl;


    C = "C++";
    std::cout << C << std::endl;
    return 0;
}
