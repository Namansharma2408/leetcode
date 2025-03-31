class Solution {
public:
    int maxi(vector<int> &nums,int i , int j){
        if( i == j ) return nums[i];
        if( i > j ) return 0;
        int k = (i+j)/2;
        int left = 0;
        int right = 0;
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        for( int x = k ; x >= i ; x--){
            left += nums[x];
            maxLeft = max(maxLeft,left);
        }
        for( int x = k+1 ; x <= j ; x++){
            right += nums[x];
            maxRight = max(maxRight,right);
        }
        return max(maxLeft+maxRight,max(maxi(nums,i,k),maxi(nums,k+1,j)));

    }
    int maxSubArray(vector<int>& nums) {
        return maxi(nums,0,nums.size()-1);
    }
};
