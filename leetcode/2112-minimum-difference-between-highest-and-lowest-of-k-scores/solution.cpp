class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort( nums.begin(),nums.end());
        int min = INT_MAX;
        for( int i = 0 ; i <= n - k ; i++){
            if( (nums[k - 1 + i] - nums[i]) < min) min = nums[k - 1 + i] - nums[i];
        }
        return min;
    }
};
