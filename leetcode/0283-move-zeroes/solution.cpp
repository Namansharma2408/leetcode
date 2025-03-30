class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while( j < n){
            if(nums[j] != 0) nums[i++] = nums[j++];
            else j++;
        }
        for( int k = i ; k < n ; k++) nums[k] = 0;
    }
};
