class Solution {
public:
    void comb(vector<int> &v, int i, int k, int n, vector<vector<int>> &result){
        if( i > n ) {
            if( v.size() == k ) result.push_back(v);
            return;
        }
        if( v.size() == k ){
            result.push_back(v);
            return;
        }
        if( v.size() > k ) return;
        v.push_back(i);
        comb(v,i+1,k,n,result);
        v.pop_back();
        comb(v,i+1,k,n,result);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        int i = 1;
        vector<vector<int>> result;
        comb(v,1,k,n,result);
        return result;
    }
};
