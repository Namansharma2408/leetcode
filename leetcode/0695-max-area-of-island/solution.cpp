class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int row, int col,int &count){
        if( row < 0 || col < 0 ) return;
        if( row >= grid.size() || col >= grid[0].size() ) return;
        if( grid[row][col] == 0 ) return;
        if( visited[row][col] == true ) return;
        visited[row][col] = true;
        count++;
        dfs(grid,visited,row+1,col,count);
        dfs(grid,visited,row-1,col,count);
        dfs(grid,visited,row,col+1,count);
        dfs(grid,visited,row,col-1,count);
        // cout<<row<<" "<<col<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int maxi = 0;
        int count = 0;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( !visited[i][j] && grid[i][j] == 1 ){
                    dfs(grid,visited,i,j,count);
                    maxi = max(maxi,count);
                    count = 0;
                }
            }
        }
        return maxi;
    }
};
