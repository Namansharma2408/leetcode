class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if( n <= 2 ) return true;
        int flag = 0;
        if( nums[0] < nums[n-1] ) flag = 1;
        else if( nums[0] > nums[n-1] ) flag = -1;
        else if( nums[0] == nums[n-1] ) flag = 0;
        if( flag == 0 ){
            for( int i = 1 ; i < n ; i++ ){
                if( nums[i] != nums[0] ) return false;
            }
            return true;
        } else if( flag == 1 ){
            for( int i = 1 ; i < n ; i++ ){
                if( nums[i] < nums[i-1] ) return false;
            }
            return true;
        }
        else if( flag == -1 ){
            for( int i = 1 ; i < n ; i++ ){
                if( nums[i] > nums[i-1] ) return false;
            }
            return true;
        }
        
        return true;
    }
};
