class Solution {
public:
    void dfs(vector<vector<int>> &rooms,vector<bool> &visited,int curr){
        visited[curr] = true;
        for( int i : rooms[curr]){
            if(!visited[i]) dfs(rooms,visited,i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,visited,0);
        for( int i = 0 ; i < n ; i++) if( visited[i] == false) return false;
        return true;
    }
};
