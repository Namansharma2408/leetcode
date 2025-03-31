class NumArray {
public:
    vector<int> arr;
    void prefix( vector<int> &nums){
        int n = nums.size();
        for( int i = 1 ; i < n ; i++) {
            nums[i] += nums[i-1];
        }
    }
    NumArray(vector<int>& nums) {
        arr = nums;
        prefix(arr);
    }    
    int sumRange(int left, int right) {
        return (left == 0) ? arr[right] : (arr[right] - arr[left-1]);
    }
};


