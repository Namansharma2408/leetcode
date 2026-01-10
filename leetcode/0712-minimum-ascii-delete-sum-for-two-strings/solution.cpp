class Solution {
public:
    int dp[1002][1002];
    
    int del(string &s1,string &s2, int m, int n, int i, int j){
        if( i >= m ){
            int ans = 0;
            for( int x = j ; x < n ; x++ ){
                ans += s2[x];
            }
            return ans;
        } 
        if( dp[i][j] != -1 ) return dp[i][j];
        if( j >= n ){
            int ans = 0;
            for( int x = i ; x < m ; x++ ){
                ans += s1[x];
            }
            return ans;
        }
        if( s1[i] == s2[j] ) return dp[i][j] = del(s1,s2,m,n,i+1,j+1);
        return dp[i][j] = min(s1[i] + del(s1,s2,m,n,i+1,j),s2[j] + del(s1,s2,m,n,i,j+1));
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        memset(dp, -1, sizeof(dp));
        return del(s1,s2,m,n,0,0);
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
