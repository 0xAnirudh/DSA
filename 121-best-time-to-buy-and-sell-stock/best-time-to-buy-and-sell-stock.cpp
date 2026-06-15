class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = INT_MAX;
        int n = prices.size();

        for(auto x : prices){
            maxprofit = max(maxprofit, x-minprice);
            minprice = min(minprice, x);
        }
        return maxprofit;
    }
};