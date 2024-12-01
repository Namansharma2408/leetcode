class Solution {
public:
    int check( vector<vector<int>> &ans,int i , int j,int m,int n){
        int val = 0;
        if(i < m-1 && ans[i+1][j] == 1) val++;
        if(j < n-1 && ans[i][j+1] == 1) val++;
        if(i > 0 && ans[i-1][j] == 1) val++;
        if(j > 0 && ans[i][j-1] == 1) val++;
        if(i < m-1 && j < n-1 && ans[i+1][j+1] == 1) val++;
        if(i > 0 && j > 0 && ans[i-1][j-1] == 1) val++;
        if(i > 0 && j < n-1 && ans[i-1][j+1] == 1) val++;
        if(i < m-1 && j > 0 && ans[i+1][j-1] == 1) val++;
        return val;

    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans = board;
        int m = board.size();
        int n = board[0].size();
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                int x  = check(ans,i,j,m,n);
                if( x < 2) board[i][j] = 0;
                else if( x > 3  && ans[i][j] == 1) board[i][j] = 0;
                else if( x == 3  && ans[i][j] == 0) board[i][j] = 1;

            }
        }
        
    }
};
