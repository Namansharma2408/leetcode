class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> arr[n];
        int m = edges.size();
        for( int i = 0 ; i < m ; i++){
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n+1,false);
        queue<int> q;
        visited[source] = true;
        q.push(source);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if( u == destination) return true;
            for( int i:arr[u]){
                if(visited[i] == false){
                    visited[i] = true;
                    q.push(i);
                }
            }   
        }
        return false;
    }
};
