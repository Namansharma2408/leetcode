class Solution {
public:
    int maxi = 0;
    int dp[21][10001];
    int OFFSET = 5000;
    int fun( int idx,int n, vector<int> &rods,int diff){
        if( idx == n ){
            return diff == 0 ? 0 : INT_MIN;
        }
        int& res = dp[idx][diff + OFFSET];
        if (res != -1) return res;  
        int h = rods[idx];

        int addLeft = fun(idx + 1, n, rods, diff + h);         // put in left
        if (addLeft != INT_MIN) addLeft += h;

        int addRight = fun(idx + 1, n, rods, diff - h);        // put in right

        int skip = fun(idx + 1, n, rods, diff);                // skip

        return res = max({addLeft, addRight, skip});
        }
        int tallestBillboard(vector<int>& rods) {
            memset(dp, -1, sizeof(dp));
            int result = fun(0, rods.size(), rods, 0);
            return result;
        }
};
