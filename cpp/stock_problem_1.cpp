#include <iostream>
#include <limits>

using namespace std;

int get_max_profit(const int prices[], const int size)
{
    int max_profit = 0;
    int min_price = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (prices[i] < min_price)
            min_price = prices[i];
        else if (prices[i] - min_price > max_profit)
            max_profit = prices[i] - min_price;
    }
    
    return max_profit;
}

int main(int argc, char const *argv[])
{   
    int prices[]{1, 9, 2, 11, 18, 20, 40, 10};
    cout << "max profit is: " << get_max_profit(prices, sizeof(prices) / sizeof(*prices)) << endl;
    return 0;
}
