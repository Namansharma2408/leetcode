class Solution {
public:
    void dfs(int i ,int j , vector<vector<char>> &grid,int m , int n){
        grid[i][j] = '0';
        if(i+1 < m && grid[i+1][j] == '1' ) dfs(i+1,j,grid,m,n);
        if(j+1 < n && grid[i][j+1] == '1' ) dfs(i,j+1,grid,m,n);
        if(i >= 1 && grid[i-1][j] == '1' ) dfs(i-1,j,grid,m,n);
        if(j >= 1 && grid[i][j-1] == '1') dfs(i,j-1,grid,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int output = 0;
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if( grid[i][j] == '1'){
                    dfs(i,j,grid,m,n);
                    output++;
                }
            }
        }
        return output;
    }
};
