class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long sum = 0;
        for( int i = 1 ; i < n ; i++){
            sum += grid[0][i];
        } 
        long long sum1 = 0;
        long long maxi = sum;
        for( int i = 1 ; i < n ; i++){
            sum -= grid[0][i];
            sum1 += grid[1][i-1];
            maxi = min(maxi,max(sum,sum1));
        }
        return maxi;
    }
};
