class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(102,0);
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ){
            v[nums[i]+1]++;
        }
        for( int i = 1 ; i < 102 ; i++ ){
            v[i] += v[i-1];
        }
        for( int i = 0 ; i < n ; i++ ){
            nums[i] = v[nums[i]];
        }
        return nums;
    }
};
