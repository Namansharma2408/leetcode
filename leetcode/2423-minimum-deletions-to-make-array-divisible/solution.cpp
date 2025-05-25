class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd_numsD = numsDivide[0];
        int n = nums.size();
        int m = numsDivide.size();
        for( int i = 1 ; i < m ; i++){
            gcd_numsD = gcd(gcd_numsD,numsDivide[i]);
        }
        int mini = INT_MAX;
        for( int i = 0 ; i < n ; i++){
            if( gcd_numsD%nums[i] == 0){
                mini = min(mini,nums[i]);
            }
        }
        if( mini == INT_MAX) return -1;
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            if( nums[i] < mini) ans++;
        }
        return ans;
    }
};
