class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
       int total = 0;
       int n = grid.size();
        for( int i = 0 ; i < n ; i++){
            int sidemax = 0;
            int frontmax = 0;
            for( int j = 0 ; j < n ; j++){
                if( grid[i][j] > 0) total++;
                if(grid[i][j] > sidemax ) sidemax = grid[i][j];
                if(grid[j][i] > frontmax ) frontmax = grid[j][i];
            }
            total += (sidemax + frontmax);
        }
        return total;
    }
};
