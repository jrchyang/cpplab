#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int>& prices) {
    int profit = 0;
    int length = prices.size();

    for (int i = 1; i < length; ++i) {
        profit += max(0, (prices[i] - prices[i-1]));
    }

    return profit;
}

int main() {
    {
        vector<int> prices = {7,1,5,3,6,4};
        cout << "profit is " << max_profit(prices) << endl;
    }
    {
        vector<int> prices = {1,2,3,4,5};
        cout << "profit is " << max_profit(prices) << endl;
    }
    {
        vector<int> prices = {7,6,4,3,1};
        cout << "profit is " << max_profit(prices) << endl;
    }

    return 0;
}
