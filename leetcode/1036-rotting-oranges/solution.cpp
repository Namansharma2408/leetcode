class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int fc = 0;
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if( grid[i][j] == 1) fc++;
                else if( grid[i][j] == 2 ) qu.push({i,j});
            }
        }
        qu.push({-1,-1});
        int minute = 0;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while( !qu.empty()){
            auto cell = qu.front();
            qu.pop();
            if(cell.first == -1 && cell.second == -1){
                minute++;
                if(!qu.empty()){
                    qu.push({-1,-1});
                }else{
                    break;
                }
            }else{
                int i = cell.first;
                int j = cell.second;
                for( int d = 0 ; d < 4 ; d++){
                    int nr = dir[d][0] + i;
                    int nc = dir[d][1] + j;
                    if( nr < 0 || nc < 0 || nr >=m || nc >= n){
                        continue;
                    }
                    if( grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                    fc--;
                    grid[nr][nc] = 2;
                    qu.push({nr,nc});

                }
            }
        }
        return (fc == 0) ? minute-1 : -1;
    }
};
