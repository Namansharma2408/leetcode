class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool b1 = true;
        bool b2 = true;
        bool b3 = true;
        bool b4 = true;
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                // same, 90 deg, 180 deg and 270 deg
                if( b1 ){
                    if( mat[i][j] != target[i][j] ) b1 = false;
                }
                if( b2 ){
                    if( mat[j][n-i-1] != target[i][j] ) b2 = false;
                }
                if( b3 ){
                    if( mat[i][j] != target[n-i-1][n-j-1] ) b3 = false;
                }
                if( b4 ){
                    if( mat[n-j-1][i] != target[i][j] ) b4 = false;
                }
                if( !(b1 || b2 || b3 || b4) ) return false;
            }
        }
        return true;
    }
};
