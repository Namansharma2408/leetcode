class NumArray {
public:
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        for( int i = 1 ; i < n ; i++){
            arr[i] += arr[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left >= 1 ) return arr[right] - arr[left-1];
        return arr[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
