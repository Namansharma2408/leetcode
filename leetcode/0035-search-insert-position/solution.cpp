class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int n = nums.size();
        int hi = n-1;
        int mid = (hi+lo)/2;
        while( hi >= lo){
            mid = (hi+lo)/2;
            if(nums[mid] == target) return mid;
            else if( nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};
