class Solution {
public:
    bool check(vector<int>& nums) {
        int pivotIdx = -1;
        int n = nums.size();
        for( int i = 1 ; i < n ; i++){
            if( nums[i] < nums[i-1]) {
                pivotIdx = i;
                break;
            }
        }
        cout<<pivotIdx<<endl;
        if( pivotIdx == -1) return true;
        for( int i = pivotIdx + 1 ; i < pivotIdx + n ; i++){
            if( nums[i%n] < nums[(i-1)%n]) return false;
        }
        return true;
    }
};
