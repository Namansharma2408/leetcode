class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowsOne(m,0);
        vector<int> colsOne(n,0);
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( grid[i][j] == 1 ){
                    rowsOne[i]++;
                    colsOne[j]++;
                }
            }
        }
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                grid[i][j] = 2*(rowsOne[i]+colsOne[j]) - n - m; 
            }
        }
        return grid;

    }
};
