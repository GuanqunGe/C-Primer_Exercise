#include <string>
class Account{
public:
    Account():Account(""){}
    Account(const std::string &s, double ia = 0): owner(s), amount(ia){}
    void calculate(){ amount += amount * InterestRate;}
    static void ChangeRate(double inrate){ InterestRate = inrate;}
    static double rate(){return InterestRate;}
private:
    std::string owner;
    double amount;
    static double InterestRate;
    static double initRate();
};

//define InterestRate
double Account::InterestRate = initRate();


double Account::initRate(){
    return 20;
}

int main(){
    Account a;
    Account b("Sheldon", 50);
    return 0;
}
