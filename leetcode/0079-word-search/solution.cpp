class Solution {
public:
    void search(string word,vector<vector<bool>> &visited,vector<vector<char>>& board,string &str,int i,int j,bool &ans,int m,int n,int idx){
        if( str == word ) {
            ans = true;
            return;
        }
        if(i+1 < m  && !ans && visited[i+1][j] == false && board[i+1][j] == word[idx]){
            str.push_back(word[idx]);
            visited[i+1][j] = true;
            search(word,visited,board,str,i+1,j,ans,m,n,idx+1);
            str.pop_back();
            visited[i+1][j] = false;
        }
        if(i >= 1 && !ans && visited[i-1][j] == false && board[i-1][j] == word[idx]){
            str.push_back(word[idx]);
            visited[i-1][j] = true;
            search(word,visited,board,str,i-1,j,ans,m,n,idx+1);
            str.pop_back();
            visited[i-1][j] = false;
        }
        if(j < n-1 && !ans && visited[i][j+1] == false && board[i][j+1] == word[idx]){
            str.push_back(word[idx]);
            visited[i][j+1] = true;
            search(word,visited,board,str,i,j+1,ans,m,n,idx+1);
            str.pop_back();
            visited[i][j+1] = false;
        }
        if(j >= 1 && !ans && visited[i][j-1] == false && board[i][j-1] == word[idx]){
            str.push_back(word[idx]);
            visited[i][j-1] = true;
            search(word,visited,board,str,i,j-1,ans,m,n,idx+1);
            str.pop_back();
            visited[i][j-1] = false;
        }



    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if( board[i][j] == word[0]){
                    string str;
                    str.push_back(word[0]);
                    bool ans = false;
                    visited[i][j] = true;
                    search(word,visited,board,str,i,j,ans,m,n,1);
                    visited[i][j] = false;
                    if( ans == true ) return true;
                }
            }
        }
        return false;
    }
};
