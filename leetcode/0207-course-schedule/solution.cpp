class Solution {
public:
    bool DFSRec(int s , vector<bool> &visited,vector<bool> &currVisited,vector<int>adj[]){
        visited[s] = true;
        currVisited[s] = true;
        for( auto x: adj[s]){
            if(!visited[x]){
                if(DFSRec(x,visited,currVisited,adj)) return true;
            }
            else if(currVisited[x]) return true;
        }
        currVisited[s] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> visited(n,false),currVisited(n,false);
        vector<int> adj[n];
        for( auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        for( int i = 0 ; i < n ; i++){
            if(!visited[i]){
                if(DFSRec(i,visited,currVisited,adj)) return false;
            }
        }
        return true;
    }
};
