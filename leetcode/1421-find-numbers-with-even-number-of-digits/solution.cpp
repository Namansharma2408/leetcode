class Solution {
public:
    bool even(int n){
        bool b = true;
        while( n != 0){
            b = !b;
            n /= 10;
        }
        return b;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) ans += even(nums[i]);
        return ans;
    }
};
