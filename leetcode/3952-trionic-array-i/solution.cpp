class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if( n < 4 ) return false;
        int maxIdx = -1;
        int minIdx = -1;
        for( int i = 1 ; i < n-1 ; i++ ){
            if( nums[i] == nums[i-1] ) return false;
            if( nums[i] > nums[i-1] && nums[i] > nums[i+1] ){
                if( maxIdx != -1 ) return false;
                else maxIdx = i;
            }else if( nums[i] < nums[i-1] && nums[i] < nums[i+1] ){
                if( minIdx != -1 ) return false;
                else minIdx = i;
            }
        }
        if( nums[n-1] == nums[n-2] ) return false;
        if( maxIdx == -1 || minIdx == -1 ) return false;
        if( maxIdx < minIdx ) return true;
        return false;
    }
};
