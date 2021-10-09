class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0, buy = prices[0];
        for (int sell:prices) {
            if (buy >= sell) {
                buy = sell;
            } else {
                int profit = sell - buy;
                if (profit > maxProfit)
                    maxProfit = profit;
            }
        }
        return maxProfit;
    }
};