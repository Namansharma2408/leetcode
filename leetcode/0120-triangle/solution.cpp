class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for( int i = 1 ; i < n ; i++ ){
            for( int j = 0 ; j <= i ; j++ ){
                if( i == j ) triangle[i][j] += triangle[i-1][j-1];
                else if( i > 0 && j > 0 ) triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
                else if( i > 0 ) triangle[i][j] += triangle[i-1][j];
            }
        }
        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ ){
            ans = min(ans,triangle[n-1][i]);
        }
        return ans;
    }
};
