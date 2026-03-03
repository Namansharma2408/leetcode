class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        vector<int> indegree(numCourses,0);
        int n = pr.size();
        for( int i = 0 ; i < n; i++ ){
            indegree[pr[i][0]]++;
        }
        queue<int> q;
        for( int i = 0 ; i < numCourses ; i++ ){
            if( indegree[i] == 0 ) q.push(i);
        }
        vector<int> topo;
        while( !q.empty() ){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for( int i = 0 ; i < n ; i++ ){
                if( pr[i][1] == node ) {
                    indegree[pr[i][0]]--;
                    if( indegree[pr[i][0]] == 0 ) q.push(pr[i][0]);
                }
            }
        }
        if( topo.size() < numCourses ) return {};
        return topo;
    }
};
