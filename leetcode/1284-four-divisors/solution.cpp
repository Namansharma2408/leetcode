class Solution {
public:
    int numOfDivisors(int n){
        int ans = 0;
        int sum = 0;
        for( int i = 1 ; i <= sqrt(n) ; i++ ){
            if( n%i == 0 ) {
                if(i != n/i)ans += 2;
                else ans += 1;
                sum += i + n/i;
            }
        }
        if( ans == 4 )return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto p : mp ){
            ans += numOfDivisors(p.first)*p.second;
        }
        return ans;
    }
};
