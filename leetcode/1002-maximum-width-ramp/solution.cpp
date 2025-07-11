class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        bool b = false;
        for( int k = 1 ; k < n ; k++){
            if( nums[k] >= nums[k-1]) {
                b = true;
                break;
            }
        }
        if( b == false) return 0;
        for (int k = 2; k <= n; k++) {
            while (j < n) {
                if (nums[i] <= nums[j])
                    return j - i;
                j++,i++;
            }
            j -= k;
            i = 0;
        }
        return 0;
    }
};
