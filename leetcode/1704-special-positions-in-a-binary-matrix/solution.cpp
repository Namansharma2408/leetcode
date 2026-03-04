class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( mat[i][j] == 1 ){
                    bool b = false;
                    for( int k = 0 ; k < n ; k++ ){
                        if( mat[i][k] == 1 && k != j ) {
                            b = true;
                            break;
                        }
                    }
                    if( b == false ){
                        for( int k = 0 ; k < m ; k++ ){
                            if( mat[k][j] == 1 && k != i ){
                                b = true;
                                break;
                            } 
                        }
                    }
                    if( b == false ) count++;
                }
            }
        }
        return count;
    }
};
