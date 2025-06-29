#define mod 1000000007
class Solution {
public:
    int power(int n){
        if( n <= 1 ) return n+1;
        long long a = (power(n/2)%((int)mod));
        a = (a*a)%((int)mod);
        if( n%2 == 1) a = (2*a)%((int)mod);
        return (int)a;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while( i <= j ){
            if( nums[i] + nums[j] <= target) {
                int p = power(j-i);
                ans = ((ans%mod) + (int)p)%mod;
                i++;
            }
            else j--;
        }
        return ans;
    }
};
