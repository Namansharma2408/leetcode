class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n-1];
        for( int i = n-3 ; i >= 0 ; i--){
            maxi = max(nums[i+2],maxi);
            nums[i] += maxi;
        }
        if( n >= 2 ) return max(nums[0],nums[1]);
        else return nums[0];
    }
};
