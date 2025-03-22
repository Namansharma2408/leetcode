class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> v(m , vector<int> (n,1));
        if( obstacleGrid[0][0] == 1) return 0;
        bool idx = 0;
        for( int i = 0 ; i < m ; i++){
            if( obstacleGrid[i][0] == 1) idx = true;
            if( idx == true) v[i][0] = 0;
            else v[i][0] = 1;
        }
        idx = false;
        for( int i = 0 ; i < n ; i++){
            if( obstacleGrid[0][i] == 1) idx = true;
            if( idx == true) v[0][i] = 0;
            else v[0][i] = 1;
        }
        for( int i = 1 ; i < m ; i++){
            for( int j = 1 ; j < n ; j++ ){
                if ( obstacleGrid[i][j] == 1) v[i][j] = 0;               
                else v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
};
