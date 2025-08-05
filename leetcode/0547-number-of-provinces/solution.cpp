class Solution {
public:
    void dfs(vector<bool> &visited,vector<vector<int>>& isConnected,int idx,int n){
        for( int i = 0 ; i < n ; i++){
            if(isConnected[idx][i] == 1 && visited[i] == false){
                visited[i] = true;
                dfs(visited,isConnected,i,n);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            if(visited[i] == false) {
                ans++;
                visited[i] = true;
                dfs(visited,isConnected,i,n);
            }
        }
        return ans;
    }
};
