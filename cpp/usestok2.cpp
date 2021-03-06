#include <iostream>
#include "stock1.h"

const int STKS = 4;
int main(int argc, char const *argv[])
{
    using std::cout;
    using std::ios_base;

    // create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithis Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5),
    };

    cout.precision(2); // #.## format 
    cout.setf(ios_base::fixed, ios_base::floatfield);// #.## format 
    cout.setf(ios_base::showpoint); // #.## format

    cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();
    std::string co = "whatever";
    Stock top = Stock(co);
    top.show();
    for (st = 1; st < STKS; st++)
        top = top.topval(stocks[st]);
    cout << "\nMost valuable holding:\n";
    top.show();

    return 0;
}
