class Solution {
public:
    int maxi(vector<vector<int>>& grid,int i,int j){
        int ans = -1;
        for( int k = 0 ; k < 3 ; k++){
            for( int l = 0 ; l < 3 ; l++){
                ans = max(ans,grid[i+k][j+l]);
            }
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n-2,vector<int>(n-2,0));
        for( int i = 0 ; i < n-2 ; i++){
            for( int j = 0 ; j < n-2 ; j++){
                v[i][j] = maxi(grid,i,j);
            }
        }
        return v;
        
    }
};
