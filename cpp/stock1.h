#ifndef STOCK1_H_
#define STOCK1_H_
#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val;  }
public:
    Stock();
    Stock(const char *co, int n = 0, double pr = 0.0);
    Stock(const std::string & co, int n = 0, double pr = 0.0);
    ~Stock();
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show() const;
    const Stock &topval(const Stock &s) const;
};

#endif