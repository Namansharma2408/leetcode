class NumMatrix {
public:
    vector<vector<int>> nums;
    void prefix(vector<vector<int>> &nums){
        int m = nums.size();
        int n = nums[0].size();
        for( int i = 1 ; i < n ; i++) nums[0][i] += nums[0][i-1];
        for( int i = 1 ; i < m ; i++){
            vector<int> arr = nums[i];
            for( int j = 1 ; j < n ; j++){
                nums[i][j] += nums[i-1][j] + arr[j-1];
                arr[j] += arr[j-1];
            }
        }
        for( int i = 1 ; i < m ; i++) nums[i][0] += nums[i-1][0];
    }
    NumMatrix(vector<vector<int>>& matrix) {
        nums = matrix;
        prefix(nums);
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        cout<<nums[row2][col2]<<endl;
        if( row1 == 0 && col1 == 0) return nums[row2][col2];
        if( row1 == row2 && col1 == col2){
            int ans = nums[row2][col2];
            if(row1 > 0 ) ans -= nums[row1-1][col2];
            if(col1 > 0 ) ans -= nums[row2][col1-1];
            if( row1 > 0 && col1 > 0) ans += nums[row1 - 1][col1-1];
            return ans;
        }
        if( row1 == 0 ) return nums[row2][col2] - nums[row2][col1-1];
        if( col1 == 0 ) return nums[row2][col2] - nums[row1-1][col2];
        else return nums[row2][col2] - nums[row2][col1-1] - nums[row1-1][col2] + nums[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
