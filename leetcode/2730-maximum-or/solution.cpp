class Solution {
public:
    long long f(int x , int y){
        long long z = x;
        for( int i = 1 ; i <= y ; i++) z *= 2;
        return z;
    }
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> before(n,0);
        vector<long long> after(n,0);
        before[0] = nums[0];
        after[n-1] = nums[n-1];
        for( int i = 1 ; i < n ; i++) before[i] = before[i-1] | nums[i];
        for( int i = n-2 ; i >= 0 ; i--) after[i] = after[i+1] | nums[i];
        long long maxi = 0;
        for( int i = 0 ; i < n ; i++){
            long long x = f(nums[i],k);
            x = x | (((i > 0) ? before[i-1] : 0) | ((i < n - 1) ? after[i+1] : 0)); 
            if( maxi < x) maxi = x;
        }
        return maxi;

    }
};
