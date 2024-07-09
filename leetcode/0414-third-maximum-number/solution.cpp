class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max = nums[0] ,secmax = INT_MIN,thirdmax = INT_MIN;
        int n = nums.size();
        bool count = 0;
        for( int i = 1 ; i < n ; i++) if(max <= nums[i]) max = nums[i];
        for( int i = 0 ; i < n ; i++) if(secmax <= nums[i] && nums[i] != max) secmax = nums[i];
        for( int i = 0 ; i < n ; i++){
            if(thirdmax <= nums[i] && nums[i] != max && nums[i] != secmax){
                thirdmax = nums[i];
                count = 1;
            }
            
        }
        if( count == 1) return thirdmax;
        else return max;
    }
};
