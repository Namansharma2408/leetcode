class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<int> &v,vector<vector<int>> &ans,int curr){
        v.push_back(curr);
        if( curr == graph.size()-1){
            ans.push_back(v);
        }
        else{
            for( auto x : graph[curr]){
                dfs(graph,v,ans,x);
            }
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> vsiited(n,false);
        dfs(graph,v,ans,0);
        return ans;
    }
};
