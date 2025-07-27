class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        for( int i = 2 ; i < n ; i++){
            maxi = max(maxi,nums[i-2]);
            if( nums[i] < maxi ) return false;
        }
        return true;
    }
};
