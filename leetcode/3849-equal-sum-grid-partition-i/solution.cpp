class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> vert(n,0);
        vector<long long> horz(m,0);
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                vert[j] += grid[i][j];
                horz[i] += grid[i][j];
            }
        }
        for( int i = 1 ; i < n ; i++ ){
            vert[i] += vert[i-1];
        }
        for( int i = 0 ; i < n - 1 ; i++ ){
            if( vert[i]*2 == vert[n-1] ) return true;
        }
        for( int i = 1 ; i < m ; i++ ){
            horz[i] += horz[i-1];
        }
        for( int i = 0 ; i < m - 1 ; i++ ){
            if( horz[i]*2 == horz[m-1] ) return true;
        }
        return false;
    }
};
