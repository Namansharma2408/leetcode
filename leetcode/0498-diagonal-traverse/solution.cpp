class Solution {
public:
    void down(vector<int> &v,vector<vector<int>> &mat,int i,int j,int m,int n,int &idx){
        while( i < m && j >= 0 ){
            v[idx++] = mat[i][j];
            i++;
            j--;
        }
        i--,j++;
    }
    void up(vector<int> &v,vector<vector<int>> &mat,int i,int j,int m,int n,int &idx){
        while( i >= 0 && j < n ){
            v[idx++] = mat[i][j];
            i--;
            j++;
        }
        i++,j--;
    }
    void c1(vector<int> &v , vector<vector<int>> &mat,int &idx){
        for( auto i : mat) v[idx++] = i[0];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if( m == 1) return mat[0];
        vector<int> v(m*n);
        int idx = 0;
        if( n == 1){
            c1(v,mat,idx);
            return v;
        }
        int i = 0;
        int j = 0;
        for( int d = 0 ; d < m + n - 1 && idx < m*n; d++){
            if( d%2 == 0){
                if( j == 0 && i < m-1){
                    up(v,mat,i,j,m,n,idx);
                    i++;
                }
                else {
                    up(v,mat,i,j,m,n,idx);
                    j++;
                }
                int sum = i + j;
                if( sum >= n) j = n - 1 , i = sum - j;
                else j = sum , i = 0;
            }else{
                if( i == 0 && j < n-1){
                    down(v,mat,i,j,m,n,idx);
                    j++;
                }
                else{
                    down(v,mat,i,j,m,n,idx);
                    i++;
                }
                int sum = i + j;
                if( sum >= m) i = m - 1 , j = sum - i;
                else  i = sum,j = 0;
            }
            
        }
        return v;
    }
};
