class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for( int i=0 ; i<m ; i++) if( grid[i][0]==0) for( int j=0 ; j<n ; j++) grid[i][j] = not grid[i][j];
        for( int i = 0 ; i < n ; i++){
            int count = 0;
            for( int j = 0 ; j < m ; j++) if( grid[j][i]==1)count++ ;
            if( count < (m+1)/2) for( int j=0 ; j<m ; j++) grid[j][i] = not grid[j][i];
        }
        int totalsum = 0;
        for( int k = 0 ; k < m ; k++){
            int mult = 1;
           for( int i = n-1 ; i >= 0 ; i--){
            totalsum += (mult*grid[k][i]);
            mult *= 2;
           }
        }
        return totalsum;
    }
};
