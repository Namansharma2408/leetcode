class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        for( int i = 0 ; i < n/2 ; i++) if( nums[i] > nums[i + n/2]) swap(nums[i],nums[i+n/2]);
        int mini = nums[0];
        for( int i = 1 ; i < n/2 ; i++) mini = min(mini,nums[i]);
        mini = min(mini,nums[n-1]);
        int maxi = nums[n/2];
        for( int i = n/2+1 ; i < n ; i++) maxi = max(maxi,nums[i]);
        maxi = max(maxi,nums[n-1]);
        
        if( maxi - mini - 2*k > 0) return maxi-mini-2*k;
        else return 0;
    }
};
