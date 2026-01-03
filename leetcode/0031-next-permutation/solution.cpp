class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // step 1 finding pivot
        int pivotIdx = -1;
        for( int i = n-1 ; i > 0 ; i-- ){
            if( nums[i] > nums[i-1]){
                pivotIdx = i-1;
                break;
            }
        }

        if( pivotIdx == -1 ){
            reverse(nums.begin(),nums.end());
            return;
        }

        // reverse after pivot
        reverse(nums.begin()+pivotIdx+1,nums.end());
        // finding just greater index
        int j = pivotIdx + 1;
        for( int i = pivotIdx + 1; i < n ; i++ ){
            if(nums[i] > nums[pivotIdx]){
                j = i;
                break;
            }
        }
        // swapping idx and idx+1
        int temp = nums[pivotIdx];
        nums[pivotIdx] = nums[j];
        nums[j] = temp;

    }
};
