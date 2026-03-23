class Solution {
public:
    vector<vector<pair<long long,long long>>> dp;
    int m, n;
    pair<long long,long long> fun(vector<vector<int>>& grid, int row, int col){
        if(dp[row][col].first != LLONG_MIN) return dp[row][col];
        long long val = grid[row][col];
        if(row == m-1 && col == n-1){
            return dp[row][col] = {val, val};
        }
        vector<long long> candidates;
        if(row + 1 < m){
            auto down = fun(grid, row+1, col);
            candidates.push_back(val * down.first);
            candidates.push_back(val * down.second);
        }
        if(col + 1 < n){
            auto right = fun(grid, row, col+1);
            candidates.push_back(val * right.first);
            candidates.push_back(val * right.second);
        }
        long long mx = *max_element(candidates.begin(), candidates.end());
        long long mn = *min_element(candidates.begin(), candidates.end());
        return dp[row][col] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MAX}));
        auto res = fun(grid, 0, 0);
        long long ans = res.first;
        if(ans < 0) return -1;
        return ans % 1000000007;
    }
};
