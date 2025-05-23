class Solution {
public:
    set<vector<int>> result;
    vector<int> v;
    void f(vector<int> &candidates,int n ,int target,int idx){
        if( 0 == target) {
            result.insert(v);
            return;
        }
        if( idx == n || target < 0 ) return;
        if( candidates[idx] <= target){
            v.push_back(candidates[idx]);
            f(candidates,n,target-candidates[idx],idx+1);
            v.pop_back();
        }
        int j = idx + 1;
        while( j < candidates.size() && candidates[j] == candidates[j-1]) j++;
        f(candidates,n,target,j);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        v.clear();
        result.clear();
        sort(candidates.begin(),candidates.end());
        f(candidates,candidates.size(),target,0);
        vector<vector<int>> ans(result.begin(),result.end());
        return ans;
    }
};
