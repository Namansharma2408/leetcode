class Solution {
public:
    int findMin(vector<int>& nums) {
        nums.push_back(INT_MAX);
        nums.insert(nums.begin(),INT_MAX);
        int n = nums.size();
        int lo = 1;
        int hi = n - 2;
        if( nums[lo] < nums[hi] ) return nums[lo];
        while( lo <= hi ){
            int mid = (lo+hi)/2;
            if( nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1] ) return nums[mid];
            else if( nums[mid] >= nums[1] ) lo = mid + 1;
            else if( nums[mid] < nums[1] ) hi = mid - 1;
        }
        return -1;
    }
};
