class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for( int i = 0 ; i < n/2 ; i++) if( n%(i+1) == 0 ) ans += (nums[i]*nums[i]);
        ans += (nums[n-1]*nums[n-1]);
        return ans;
    }
};
