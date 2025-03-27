class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for( int i = 0 ; i < 9 ; i++){
            unordered_map<char,int> mp;
            for( int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.')mp[board[i][j]]++;
                if(mp[board[i][j]] > 1) return false;
            }
        }
        for( int i = 0 ; i < 9 ; i++){
            unordered_map<char,int> mp;
            for( int j = 0 ; j < 9 ; j++){
                if(board[j][i] != '.')mp[board[j][i]]++;
                if(mp[board[j][i]] > 1) return false;
            }
        }
        for( int i = 0 ; i < 9 ; i+=3){
            for( int j = 0 ; j < 9 ; j += 3){
                unordered_map<char,int> mp;
                for( int k = 0 ; k < 3 ; k++){
                    for( int l = 0 ; l < 3 ; l++){
                        if(board[i+k][j+l] != '.') mp[board[i+k][j+l]]++;
                        if(mp[board[i+k][j+l]] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};
