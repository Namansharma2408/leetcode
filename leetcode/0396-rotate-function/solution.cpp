class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++) sum += nums[i];
        int currF = 0;
        for( int i = 1 ; i < n ; i++) currF += i*nums[i];
        int maxi = currF;
        int newF;
        for( int i = 1 ; i < n ; i++) {
            newF = sum + currF - n*nums[n-i];
            maxi = max(maxi,newF);
            currF = newF;
        }
        return maxi;

    }
};
