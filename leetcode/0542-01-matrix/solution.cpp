class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> v(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0 ){
                    v[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dis = {{1,0},{0,1},{-1,0},{0,-1}};
        while( !q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            for( int d = 0 ; d < 4 ; d++){
                int nr = i + dis[d][0];
                int nc = j + dis[d][1];
                if( nr < 0 || nc < 0 || nr >= m || nc >= n || v[nr][nc] == 0 ) continue;
                if(v[nr][nc] > v[i][j]) {
                    v[nr][nc] = v[i][j]+1;
                    q.push({nr,nc});
                }
            }

        }
        return v;
    }
};
