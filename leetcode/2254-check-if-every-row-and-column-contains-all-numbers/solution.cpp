class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        set<int> st;
        int n = matrix.size();
        for( int i = 0 ; i < n ; i++ ){
            st.clear();
            for( int j = 0 ; j < n ; j++ ){
                int x = matrix[i][j];
                if( x >= 1 && x <= n ) st.insert(x);
            }
            if( st.size() < n ) return false;
        }
        for( int i = 0 ; i < n ; i++ ){
            st.clear();
            for( int j = 0 ; j < n ; j++ ){
                int x = matrix[j][i];
                if( x >= 1 && x <= n ) st.insert(x);
            }
            if( st.size() < n ) return false;
        }
        return true;
    }
};
