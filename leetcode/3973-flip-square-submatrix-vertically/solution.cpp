class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for( int i = x ; i < x + (k)/2 ; i++ ){
            for( int j = y ; j < y + k ; j++ ){
                int temp = grid[i][j];
                grid[i][j] = grid[2*x+k-i-1][j];
                grid[2*x+k-i-1][j] = temp;
            }
        }
        return grid;
    }
};
