class Solution {
    bool isMagic(vector<vector<int>>& grid, int r, int c, int k,
                 vector<vector<int>>& rows, vector<vector<int>>& cols,
                 vector<vector<int>>& d1, vector<vector<int>>& d2) {

        int target = rows[r][c + k] - rows[r][c];
        for (int i = 1; i < k; ++i) {
            if (rows[r + i][c + k] - rows[r + i][c] != target) return false;
        }
        for (int j = 0; j < k; ++j) {
            if (cols[r + k][c + j] - cols[r][c + j] != target) return false;
        }
        if (d1[r + k][c + k] - d1[r][c] != target) return false;
        if (d2[r + k][c] - d2[r][c + k] != target) return false;
        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rows(m, vector<int>(n + 1, 0));
        vector<vector<int>> cols(m + 1, vector<int>(n, 0));
        vector<vector<int>> d1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d2(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i][j + 1] = rows[i][j] + grid[i][j];
                cols[i + 1][j] = cols[i][j] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (isMagic(grid, i, j, k, rows, cols, d1, d2)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};
