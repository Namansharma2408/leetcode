class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int smallestAbsValue = INT_MAX;
        int noOfNegative = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                int x = abs(matrix[i][j]);
                ans += x;
                if(matrix[i][j] <= 0) noOfNegative++;
                smallestAbsValue = min(smallestAbsValue,x);
            }
        }

        if( noOfNegative%2 == 0 ) return ans;
        else return ans - 2*smallestAbsValue;
    }
};
