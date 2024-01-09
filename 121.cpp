#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int length = prices.size();
        int buy = prices[0], profit = 0;

        for (int i = 1; i < length; i++)
        {
            if (prices[i] - buy > profit)
            {
                profit = prices[i] - buy;
            }
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
        }
        return profit;
    }
};

int main()
{
    // Solution sol;
    vector<int> prices = {1, 2};

    return 0;
}