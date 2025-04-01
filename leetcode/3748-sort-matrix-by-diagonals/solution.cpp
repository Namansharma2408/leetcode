class Solution {
public:
    void diagonalSort1(vector<vector<int>>& grid,int i,int j,int n){
        priority_queue<int,vector<int>,greater<int>> pq;
        while(i < n && j < n) pq.push(grid[i++][j++]);
        i--,j--;
        while( i >= 0 && j >= 0){
            grid[i--][j--] = pq.top();
            pq.pop();
        }
    }
    void diagonalSort2(vector<vector<int>>& grid,int i,int j,int n){
        priority_queue<int> pq;
        while(i < n && j < n) pq.push(grid[i++][j++]);
        i--,j--;
        while( i >= 0 && j >= 0){
            grid[i--][j--] = pq.top();
            pq.pop();
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for( int i = 0 ; i < n ; i++) diagonalSort1(grid,i,0,n);
        for( int i = 1 ; i < n ; i++) diagonalSort2(grid,0,i,n);
        return grid;
    }
};
