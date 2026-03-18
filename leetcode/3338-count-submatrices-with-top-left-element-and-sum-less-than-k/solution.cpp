class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( i > 0 ) grid[i][j] += grid[i-1][j];
                if( j > 0 ) grid[i][j] += grid[i][j-1];
                if( j > 0 && i > 0 ) grid[i][j] -= grid[i-1][j-1];
                if( grid[i][j] <= k ) {
                    ans++;
                }
                if( grid[i][j] > k ) break;
            }
        }
        return ans;
    }
};
