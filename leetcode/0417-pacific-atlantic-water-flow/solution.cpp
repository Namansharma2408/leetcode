class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int col;
    int row;
    vector<vector<int>> h;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        row = heights.size();
        col = heights[0].size();

        queue<pair<int,int>> pacificBfs;
        queue<pair<int,int>> atlanticBfs;

        for( int i = 0 ; i < row ; i++){
            pacificBfs.push({i,0});
            atlanticBfs.push({i,col-1});
        }
        for( int i = 1 ; i < col ; i++){
            pacificBfs.push({0,i});
        }
        for( int i = 0 ; i < col - 1 ; i++){
            atlanticBfs.push({row - 1,i});
        }
        vector<vector<bool>> pacificVisited = bfs(pacificBfs);
        vector<vector<bool>> atlanticVisited = bfs(atlanticBfs);
        vector<vector<int>> ans;
        for( int i = 0 ; i < row ; i++){
            for( int j = 0 ; j < col ; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    vector<vector<bool>> bfs(queue<pair<int,int>> &q){
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        while( !q.empty()){
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for( int d = 0 ; d < 4 ; d++){
                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];
                if( newRow < 0 || newCol < 0 || newRow >= row || newCol >= col ) continue;
                if( visited[newRow][newCol]) continue;
                if( h[newRow][newCol] < h[i][j]) continue;
                q.push({newRow,newCol});
            }
        }
        return visited;
    }
};
