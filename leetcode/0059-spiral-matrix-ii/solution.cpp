class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,0));
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int a = 1;
        while( left <= right && top <= bottom){
            for( int i = left ; i <= right;i++) v[top][i] = a++;
            top++;
            for( int i = top ; i <= bottom;i++) v[i][right] = a++;
            right--;
            for( int i = right ; i >= left;i--) v[bottom][i] = a++;
            bottom--;
            for( int i = bottom ; i >= top;i--) v[i][left] = a++;
            left++;
        }
        return v;
    }
};
