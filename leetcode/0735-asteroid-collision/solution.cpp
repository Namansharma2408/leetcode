class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans;
        int n = ast.size();
        for( int i = 0 ; i < n ; i++ ){
            if( ans.size() == 0 ) ans.push_back(ast[i]);
            else {
                if( ans[ans.size()-1] > 0 && ast[i] < 0 ){
                    if( ans[ans.size()-1] < -ast[i] ){
                        ans.pop_back();
                        i--;
                    } else if( ans[ans.size()-1] == -ast[i] ){
                        ans.pop_back();
                    }
                } else {
                    ans.push_back(ast[i]);
                }
            }
        }
        return ans;
    }
};
