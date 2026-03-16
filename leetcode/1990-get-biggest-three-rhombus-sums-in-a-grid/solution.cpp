class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        // size of rhombus can be 1 to (n+1)/2
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> sum(m,vector<pair<int, int>>(n, {0, 0}));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int leftdiag = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) {
                    leftdiag += sum[i - 1][j - 1].first;
                }
                int rightdiag = grid[i][j];
                if (i - 1 >= 0 && j + 1 < n) {
                    rightdiag += sum[i - 1][j + 1].second;
                }
                sum[i][j] = {leftdiag, rightdiag};
            }
        }

        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_set<int> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k >= 0; k -= 2) {
                    int perimeter;
                    if (k == i) {
                        perimeter = grid[i][j];
                        if(st.find(perimeter) == st.end() ) {
                            pq.push(perimeter);
                            st.insert(perimeter);
                        }
                        if (pq.size() > 3)
                            pq.pop();
                    } else {
                        if (j < (i - k) / 2)
                            continue;
                        if (j + (i - k) / 2 >= n)
                            continue;
                        perimeter = sum[i][j].first + sum[i][j].second - grid[i][j];
                        perimeter += sum[(i + k) / 2][j - (i - k) / 2].second;
                        perimeter -= sum[(i + k) / 2][j - (i - k) / 2].first;
                        perimeter -= sum[(i + k) / 2][j + (i - k) / 2].second;
                        perimeter += sum[(i + k) / 2][j + (i - k) / 2].first;
                        perimeter -= sum[k][j].first;
                        perimeter -= sum[k][j].second;
                        perimeter += grid[k][j];
                        if(st.find(perimeter) == st.end() ) {
                            pq.push(perimeter);
                            st.insert(perimeter);
                        }
                        if (pq.size() > 3)
                            pq.pop();
                    }
                }
            }
        }
        vector<int> ans(3);
        ans[2] = pq.top();
        pq.pop();
        ans[1] = pq.top();
        pq.pop();
        ans[0] = pq.top();
        pq.pop();
        if( ans[1] == ans[2] ) {
            ans.pop_back();
            if( ans[1] == ans[0] ) ans.pop_back();
            return ans;
        }
        if( ans[1] == ans[0] ) ans.erase(ans.begin()+1);
        return ans;
    }
};
