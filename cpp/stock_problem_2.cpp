#include <iostream>
#include <vector>

using namespace std;

// int get_max_profit(vector<int> & prices)
// {
//     int min_so_far = -1;
//     int profit = 0;
//     int i = 0;
//     int p_size = prices.size();
//     for (; i < p_size - 1; i++)
//     {
//         if (min_so_far == -1 && prices[i] < prices[i + 1])
//             min_so_far = prices[i];
//         else if (min_so_far != -1 && prices[i] > prices[i + 1])
//         {
//             profit += prices[i] - min_so_far;
//             min_so_far = -1;
//         }
//     }
//     if (i > 0 && min_so_far != -1 && prices[i] > min_so_far)
//         profit += prices[i] - min_so_far;
//     return profit;
// }


int get_max_profit(vector<int> & prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices;
    cout << "prices size: " << prices.size() << endl;
    cout << "max profit: " << get_max_profit(prices) << endl;
    prices.push_back(3);
    prices.push_back(10);
    prices.push_back(2);
    prices.push_back(2);
    prices.push_back(9);
    prices.push_back(9);
    cout << "prices size: " << prices.size() << endl;
    cout << "max profit: " << get_max_profit(prices) << endl;
    return 0;
}
