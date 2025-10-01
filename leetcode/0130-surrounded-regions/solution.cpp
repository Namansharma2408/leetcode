class Solution {
public:
    void dfs(vector<vector<char>>&board,int i, int j, int n, int m){
        if( i < 0 || j < 0 || i == m || j == n ) return;
        if( board[i][j] != 'O') return;
        board[i][j] = 'Y';
        dfs(board,i+1,j,n,m);
        dfs(board,i-1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for( int i = 0; i < m ; i++ ){
            if(board[i][0] == 'O') dfs(board,i,0,n,m);
            if(board[i][n-1] == 'O') dfs(board,i,n-1,n,m);
        }
        for( int i = 1; i < n-1 ; i++ ){
            if(board[0][i] == 'O') dfs(board,0,i,n,m);
            if(board[m-1][i] == 'O') dfs(board,m-1,i,n,m);
        }
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};
