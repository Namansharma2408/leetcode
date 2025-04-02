class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> aageMax(n);
        aageMax[n-1] = INT_MIN;
        int maxi = INT_MIN;
        for( int i = n-2 ; i >= 0 ; i--){
            maxi = max(maxi , nums[i+1]);
            aageMax[i] = maxi;
        }
        vector<int> picheMax(n);
        picheMax[0] = INT_MIN;
        maxi = INT_MIN;
        for( int i = 1 ; i < n ; i++){
            maxi = max(maxi,nums[i-1]);
            picheMax[i] = maxi;
        }
        long long ans = 0;
        for( int j = 1 ; j < n-1 ; j++){
            long long x = (picheMax[j] - nums[j])*(long long)aageMax[j];
            if( ans < x) ans = x;
        }

        return ans;
    }
};
