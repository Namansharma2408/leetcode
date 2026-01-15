class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rs = 0, re = m-1, cs = 0, ce = n-1;
        int count = 0;
        vector<int> ans;
        while( true ){
            for( int i = cs ; i <= ce ; i++ ){
                ans.push_back(matrix[rs][i]);
                if( ans.size() == m*n) return ans;
            }
            rs++;
            for( int i = rs ; i <= re ; i++ ){
                ans.push_back(matrix[i][ce]);
                if( ans.size() == m*n) return ans;
            }
            ce--;
            for( int i = ce ; i >= cs ; i-- ){
                ans.push_back(matrix[re][i]);
                if( ans.size() == m*n) return ans;
            }
            re--;
            for( int i = re ; i >= rs ; i-- ){
                ans.push_back(matrix[i][cs]);
                if( ans.size() == m*n) return ans;
            }
            cs++;
        }
        return ans;
    }
};
