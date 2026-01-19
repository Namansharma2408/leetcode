class Solution {
public:
    bool check(vector<vector<int>>& mat, int size, int m, int n, int threshold){
        for( int i = 0 ; i <= m - size ; i++ ){
            for( int j = 0 ; j <= n - size ; j++ ){
                if( i > 0 && j > 0 ){
                    if( (mat[i+size-1][j+size-1] - mat[i-1][j+size-1] - mat[i+size-1][j-1] + mat[i-1][j-1]) <= threshold ) {
                        return true;
                    }
                } 
                else if( i > 0 ){
                    if( (mat[i+size-1][j+size-1] - mat[i-1][j+size-1]) <= threshold ) {
                        return true;
                    }
                }
                else if( j > 0 ){
                    if( (mat[i+size-1][j+size-1] - mat[i+size-1][j-1]) <= threshold ) {
                        return true;
                    }
                }
                else {
                    if( mat[i+size-1][j+size-1] <= threshold ) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if(i > 0 && j > 0)mat[i][j] += mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
                else if(i > 0) mat[i][j] += mat[i-1][j];
                else if(j > 0) mat[i][j] += mat[i][j-1];

            }
        }
        int lo = 1;
        int hi = min(m,n);
        while( lo <= hi ){
            int mid = (lo+hi)/2;
            if( check(mat,mid,m,n,threshold) ) lo = mid + 1;
            else hi = mid-1;
        }

        return hi;
    }
};
