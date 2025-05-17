class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows,vector<int> (1,1));
        for( int i = 1 ; i < numRows ; i++){
            for( int j = 1 ; j <= i ; j++){
                int num;
                i != j ? num = (v[i][j-1] *(i-j+1))/(j) : num = 1;
                v[i].push_back(num);
            }
        }
        return v;
    }
};
