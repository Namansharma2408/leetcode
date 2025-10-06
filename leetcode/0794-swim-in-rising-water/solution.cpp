class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int maxi = grid[0][0];
        visited[0][0] = true;
        pq.push({grid[0][0],{0,0}});
        while( !pq.empty() ){
            maxi = max(maxi,pq.top().first);
            auto p = pq.top();
            pq.pop();
            int r = p.second.first;
            int c = p.second.second;
            // cout<<" r-> "<<r<<" c-> "<<c<<" num => "<<p.first<<endl;
            if( r == m-1 && c == n-1 ) return maxi;
            if(  r >= 1 && !visited[r-1][c]){
                visited[r-1][c] = true;
                pq.push({grid[r-1][c],{r-1,c}});
            }
            if( r < m-1 && !visited[r+1][c]){
                visited[r+1][c] = true;
                pq.push({grid[r+1][c],{r+1,c}});
            }
            if( c >= 1 && !visited[r][c-1]){
                visited[r][c-1] = true;
                pq.push({grid[r][c-1],{r,c-1}});
            }
            if( c < n-1 && !visited[r][c+1]){
                visited[r][c+1] = true;
                pq.push({grid[r][c+1],{r,c+1}});
            }
        }

        return maxi;
    }
};
