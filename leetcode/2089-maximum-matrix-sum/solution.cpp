class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negative = 0;
        long long sum = 0;
        int min;
        matrix[0][0] >= 0 ? min = matrix[0][0] : min = -matrix[0][0];
        for( auto i : matrix){
            for( int j : i){
                if( j < 0){
                    negative++;
                    sum -= j;
                    if( j > -min) min = -j;
                }
                else {
                    sum += j;
                    if( j < min) min = j;
                }
            }
        }
        if( negative%2 == 0) return sum;
        else return (sum - (2*min));
    }
};
