class Solution {
public:
    void rotateindex(vector<int> & nums,int i , int j){
        while( i < j){
            nums[j] += nums[i];
            nums[i] = nums[j] - nums[i];
            nums[j] -= nums[i];
            i++,j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        rotateindex(nums,0,n-1);
        rotateindex(nums,0,k-1);
        rotateindex(nums,k,n-1);
    }
};
