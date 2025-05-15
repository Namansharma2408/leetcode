class Solution {
    void transpose(vector<vector<int>>& matrix,int n){
        for( int i = 1 ; i < n ; i++){
            for( int j = 0 ; j <= i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void horizontalReverse(vector<vector<int>>& matrix,int n){
        for( int i = 0 ; i < n ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix,n);
        horizontalReverse(matrix,n);
    }
};
