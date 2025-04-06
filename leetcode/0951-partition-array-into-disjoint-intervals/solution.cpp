class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,nums.back());
        v[n-1] = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i--) v[i] = min(nums[i],v[i+1]);
        int maxi = 0;
        for( int i = 0 ; i < n ; i++){
            maxi = max(maxi,nums[i]);
            if( maxi <= v[i+1]) return i+1;
        }
        return 0;
    }
};

