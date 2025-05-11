class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sumFormed = 0;
        long long expectedSum = 1;
        int minPatches = 0;
        int i = 0;
        int m = nums.size();
        while(sumFormed < n){
            if( sumFormed >= expectedSum){
                expectedSum = sumFormed+1;
            }else{
                if( i < m && nums[i] <= expectedSum){
                    sumFormed += nums[i];
                    i++;
                }
                else{
                    minPatches++;
                    sumFormed += expectedSum;
                }
            }
        }
        return minPatches;
    }
};
