class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxi = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        int i = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while (!pq.empty()) {
            auto [val, pos] = pq.top();
            maxi = max(maxi,val);
            pq.pop();
            int x = pos.first, y = pos.second;
            if ((x == m - 1) && (y == n - 1))
                return maxi;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    !visited[nx][ny]) {
                    pq.push({grid[nx][ny], {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }
        return maxi;
    }
};
