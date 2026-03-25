class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        vector<int> v(2,-1);
        while( lo <= hi ){
            int mid = (lo+hi)/2;
            if( nums[mid] == target && ( (mid == 0) || nums[mid-1] < target) ) {
                v[0] = mid;
                break;
            }
            else if( nums[mid] < target ) lo = mid + 1;
            else hi = mid - 1;
        }
        if( v[0] == -1 ) return v;
        lo = v[0];
        hi = n-1;
        while( lo <= hi ){
            int mid = (lo+hi)/2;
            if( nums[mid] == target && ( (mid == n-1) || nums[mid+1] > target) ) {
                v[1] = mid;
                break;
            }
            else if( nums[mid] <= target ) lo = mid + 1;
            else hi = mid - 1;
        }
        return v;
    }
};
