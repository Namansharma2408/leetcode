class Solution {
public:

    bool DFSRec(int i,vector<bool>&visited,vector<bool>&dfsVisited , vector<vector<int>>& graph,vector<bool> &presentCycle){
        visited[i] = true;
        dfsVisited[i] = true;
        for( auto x : graph[i]){
            if( !visited[x]){
                if(DFSRec(x,visited,dfsVisited,graph,presentCycle)){
                    return presentCycle[i] = true;
                }
            }else if( dfsVisited[x]){
                return presentCycle[i] = true;
            }
        }
        dfsVisited[i] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> ans;
        vector<bool> visited(v,false),dfsVisited(v,false),presentCycle(v,false);

        for( int i = 0 ; i < v ; i++){
            if( !visited[i]) DFSRec(i,visited,dfsVisited,graph,presentCycle);
        }
        for( int i = 0 ; i < v ; i++){
            if(!presentCycle[i]) ans.push_back(i);
        }
        return ans;
    }
};
