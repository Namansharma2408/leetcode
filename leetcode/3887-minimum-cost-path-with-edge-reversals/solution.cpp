class Solution {
public:
    typedef pair<int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<p>> adj;
        for( auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> result(n,INT_MAX);
        result[0] = 0;
        pq.push({0,0});
        while( !pq.empty() ){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if( node == n-1 ){
                return result[n-1];
            }
            for( auto &p:adj[node]){
                int adjNode = p.first;
                int dist = p.second;
                if( d+dist < result[adjNode]){
                    result[adjNode] = d+dist;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }
        return -1;
    }
};
