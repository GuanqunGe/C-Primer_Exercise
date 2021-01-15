#include <iostream>
#include <string>
#include <fstream>

using std::string;
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

    
    double avg_price(){   //defined inside the class, implicitly inline.
	if(units_sold) return revenue/units_sold;
	else return 0;
    }
    //double avg_price() const { return units_sold ? revenue/units_sold : 0 ;}   //much better one.

    public:
    //constructor
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s){}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &is){ read(is, *this); }

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



int main(int argc, char **argv){
    if(argc < 3){
      	std::cerr << "Need two arguments as filenames to read and write " << std::endl;
        return -1;
    }

    std::ifstream infile(argv[1]);
    if(!infile){
 	std::cerr << "Couldn't successfully open the file: " << argv[1] << std::endl;
        return -1;
    }

    std::ofstream outfile(argv[2], std::ofstream::app); //implicitly out mode + explict append mode
    if(!outfile){
	std::cerr << "Coldn't open the file to write: " << argv[2] << std::endl;
	return -1;
    }

    outfile << "\n" << std::endl;  //add empty line to the output file


    Sales_data total;
    double unit_price;
    if(read(infile, total)){
        Sales_data trans;
        while(read(infile, trans)){
            if(trans.isbn() == total.isbn()){
                total.combine(trans);
            }
            else{
		print(outfile, total) << std::endl;  //endl adds a new line character and flushes the buffer to the file
		//print(outfile, total);
		total = trans; 
            }
        }
	print(outfile, total); // buffer will be flushed at the end of program execution
	//print(outfile, total) << std::endl; 
    }else{
        std::cerr << "No data?!" << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
