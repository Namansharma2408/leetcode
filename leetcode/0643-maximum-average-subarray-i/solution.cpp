class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double d = 0;
        for( int i = 0 ; i < k ; i++) d += nums[i];
        double ans = d;
        for( int i = k ; i < n ; i++){
            d += nums[i];
            d -= nums[i-k];
            ans = max(ans,d);
        }
        return (ans/k);
    }
};
