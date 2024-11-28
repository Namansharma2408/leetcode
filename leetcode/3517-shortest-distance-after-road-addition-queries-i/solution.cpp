class Solution {
public:
    int searchInBFS(vector<vector<int>> &v,int n){
        vector<bool> visited(n,false);
        visited[0] = true;
        vector<int> level(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if( u == n-1) return level[n-1];
            for( int i : v[u]){
                if( !visited[i]){ 
                    q.push(i);
                    visited[i] = true;
                    level[i] = level[u] + 1;
                }
            }
        }
        return level[n-1];
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n);
        int j = 0;
        for( int i = 0 ; i < n-1 ; i++){
            v[i].push_back(i+1);
        }
        vector<int> ans;
        int m = queries.size();
        for( int i = 0 ; i < m ; i++ ){
            v[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(searchInBFS(v,n));
        }
        return ans;
    }
};
