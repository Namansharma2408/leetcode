class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices[n-1];
        int maxProfit = 0;
        for( int i = n-2 ; i >= 0 ; i--){
            maxProfit = max(maxProfit,maxi-prices[i]);
            maxi = max(maxi,prices[i]);
        }
        return maxProfit;
    }
};
