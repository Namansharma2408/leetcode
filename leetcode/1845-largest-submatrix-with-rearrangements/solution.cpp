class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( i == 0 ) continue;
                else if( matrix[i][j] == 0 ) matrix[i][j] = 0;
                else if( matrix[i][j] == 1 ) matrix[i][j] += matrix[i-1][j];
            }
        }
        for( int i = 0 ; i < m ; i++ ){
            sort(matrix[i].begin(),matrix[i].end());
        }
        int ans = 0;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                int temp = matrix[i][j]*(n-j);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
