class Solution {
public:
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, -1)));
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if( startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n ) return 1;
        if( maxMove == 0 ) return 0;
        if( dp[maxMove][startRow][startColumn] != -1 ) return dp[maxMove][startRow][startColumn];
        long long ans = 0;
        ans += findPaths(m,n,maxMove-1,startRow+1,startColumn);
        ans += findPaths(m,n,maxMove-1,startRow-1,startColumn);
        ans += findPaths(m,n,maxMove-1,startRow,startColumn+1);
        ans += findPaths(m,n,maxMove-1,startRow,startColumn-1);
        return dp[maxMove][startRow][startColumn] = ans%mod;
    }
};
