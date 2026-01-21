class Solution {
public:
int minNum(int num){
        int count = 0;
        int ans = num;
        while( num%2 == 1 ){
            num /= 2;
            count++;
        }
        ans -= pow(2,count-1);
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        for( int i = 0 ; i < n ; i++ ){
            if( nums[i] == 2 ) nums[i] = -1;
            else {
                nums[i] = minNum(nums[i]);
            }
        }
        return nums;
    }
};
