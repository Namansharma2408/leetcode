class Solution {
public:
    int rev(int number){
        int reverse = 0;
        while(number != 0){
            reverse *= 10;
            reverse += number%10;
            number /= 10;
        }
        return reverse;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) nums[i] = nums[i] - rev(nums[i]);
        unordered_map<int,int> m;
        long long ans = 0;
        for( int i = 0 ; i < n ; i++){ 
            if(m.find(nums[i]) != m.end()) ans += m[nums[i]];
            m[nums[i]]++;      
        }
        ans %= (long long)(1e9 + 7);
        return (int)ans;
    }
};
