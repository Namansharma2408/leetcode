#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll f(int n , int k , int t,vector<vector<ll>> &dp){
        if( n == 0 && t == 0) return 1;
        if( n == 0 ) return 0;
        int sum = 0;
        if( dp[n][t] != -1) return dp[n][t];
        for( int v = 1 ; v <= k ; v++){
            if(t-v >= 0)sum += (f(n-1,k,t-v,dp)%mod);
            sum %= mod;
        }
        return dp[n][t] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n+1,vector<ll> (target+1,-1));
        return (int)f(n,k,target,dp);

    }
};
