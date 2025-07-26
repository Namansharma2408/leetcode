class Solution {
public:
    vector<pair<int,int>> internal;
    void dfs(vector<vector<int>> &grid, int r, int c, int color, int newColor){
        if( r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != color) return;
        grid[r][c] = -newColor;
        dfs(grid,r+1,c,color,newColor);
        dfs(grid,r,c+1,color,newColor);
        dfs(grid,r-1,c,color,newColor);
        dfs(grid,r,c-1,color,newColor);
        if( !(r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1 || grid[r-1][c] != -newColor || grid[r+1][c] != -newColor || grid[r][c-1] != -newColor || grid[r][c+1] != -newColor)){
            internal.push_back({r,c});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int orignalColor = grid[row][col];
        if( orignalColor == color ) return grid;
        dfs(grid,row,col,orignalColor,color);
        for( auto p : internal){
            grid[p.first][p.second] = orignalColor;
        }
        for( int i = 0 ; i < grid.size() ; i++){
            for( int j = 0 ; j < grid[0].size(); j++){
                if( grid[i][j] == -color) grid[i][j] = color;
            }
        }
        return grid;
    }
};
