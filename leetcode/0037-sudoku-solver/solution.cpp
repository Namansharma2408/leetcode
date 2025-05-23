class Solution {
public:
    bool isSafe( vector<vector<char>> &board,int r,int c,int num){
        for( int i = 0 ; i < 9 ; i++){
            if( board[r][i] == num + '0' || board[i][c] == num + '0') return false;
        }
        for( int i = (r/3)*3 ; i < (r/3)*3 + 3 ; i++){
            for( int j = (c/3)*3 ; j < (c/3)*3 + 3 ; j++){
                if( board[i][j] == num + '0') return false;
            }
        }
        return  true;
    }
    bool f(vector<vector<char>> &board,int r , int c){
        if( r == 9) return true;
        if( c == 9) return f(board,r+1,0);
        if( board[r][c] != '.') return f(board,r,c+1);
        for( int j = 1 ; j <= 9 ; j++){
            if( isSafe(board,r,c,j)){
                board[r][c] = '0'+j;
                bool b = f(board,r,c+1);
                if( b ) return true;
                board[r][c] = '.';
            }
        }
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
    }
};
