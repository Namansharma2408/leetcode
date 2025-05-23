class Solution {
public:
    int ans;
    vector<string> grid;
    bool canPlaceQueen(int col,int row,int n){
        // column
        for( int i = row-1 ; i >= 0 ; i--){
            if( grid[i][col] == 'Q') return false;
        }
        // left diagonal
        for( int i = row-1,j = col-1 ; i >= 0 && j >= 0 ; i--,j--){
            if( grid[i][j] == 'Q') return false;
        }
        // right diagonal
        for( int i = row-1,j = col+1 ; i >= 0 && j < n ; i--,j++){
            if( grid[i][j] == 'Q') return false;
        }
        return true;
    }
    void f(int row , int n){
        if( row == n) {
            ans++;
            return;
        }
        for( int col = 0 ; col < n ; col++ ){
            if( canPlaceQueen(col,row,n)){
                grid[row][col] = 'Q';
                f(row+1 , n);
                grid[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        grid.clear();
        grid.resize(n,string(n,'.'));
        f(0,n);
        return ans;
    }
};
