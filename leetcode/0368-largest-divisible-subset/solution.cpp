class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,0);
        vector<int> prev(n,-1);
        for( int i = 1 ; i < n ; i++){
            for( int j = 0 ; j < i ; j++){
                if( nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        int maxi = dp[0];
        int maxIdx = 0;
        for( int i = 1 ; i < n ; i++) {
            if( maxi < dp[i]){
                maxi = dp[i];
                maxIdx = i;
            }
        }
        vector<int> ans;
        while(maxIdx >= 0){
            ans.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
