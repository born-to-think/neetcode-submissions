class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int profit=0;
        int minBuy = prices[0];

        for(int& sellPrice :prices){
            profit = max(profit, sellPrice-minBuy);
            minBuy=min(minBuy,sellPrice);
        }
        return profit;
    }
};
