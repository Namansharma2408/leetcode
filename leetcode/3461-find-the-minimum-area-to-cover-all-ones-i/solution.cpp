class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();
        int cmin = n-1;
        int rmin = m-1;
        int cmax = 0;
        int rmax = 0;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( grid[i][j] == 1 ){
                    cmin = min(j,cmin);
                    rmin = min(i,rmin);
                    cmax = max(j,cmax);
                    rmax = max(i,rmax);
                }
            }
        }
        area = (cmax - cmin + 1)*(rmax - rmin + 1);
        return area;
    }
};
