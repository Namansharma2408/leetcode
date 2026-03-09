class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int leftzero, int leftone, bool last, int limit){
        if( leftzero == 0 && leftone == 0 ){
            return 1;
        }
        if( dp[leftzero][leftone][(int)last] != -1 ) return dp[leftzero][leftone][(int)last];
        int result = 0;
        if( last == false ){
            for( int i = 1 ; i <= min(leftone,limit) ; i++ ){
                result = (result+solve(leftzero,leftone-i,true,limit))%mod;
            }
        } else {
            for( int i = 1 ; i <= min(leftzero,limit) ; i++ ){
                result = (result+solve(leftzero-i,leftone,false,limit))%mod;
            }
        }
        return dp[leftzero][leftone][(int)last] = result%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        dp.resize(zero+1,vector<vector<int>>(one+1,vector<int>(2,-1)));
        return (solve(zero,one,false,limit)%mod+solve(zero,one,true,limit)%mod)%mod;
    }
};
