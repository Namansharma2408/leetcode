class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long curr = mass;
        int n = ast.size();
        for( int i = 0 ; i < n ; i++ ){
            if( ast[i] > curr ) return false;
            curr += ast[i];
        }
        return true;
    }
};
