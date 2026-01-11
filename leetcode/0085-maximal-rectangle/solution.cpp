class Solution {
public:
    vector<int> next(vector<int> &height){
        int n = height.size();
        vector<int> nextSmaller(n,n);
        stack<int> s;
        for( int i = n-1 ; i >= 0 ; i-- ){
            while( s.size() > 0 && height[s.top()] >= height[i]){
                s.pop();
            }
            if( s.size() != 0 ){
                nextSmaller[i] = s.top();
            }
            s.push(i);
        }
        return nextSmaller;
    }
    vector<int> prev(vector<int> &height){
        int n = height.size();
        vector<int> prevSmaller(n,-1);
        stack<int> s;
        for( int i = 0 ; i < n ; i++ ){
            while( s.size() > 0 && height[s.top()] >= height[i]){
                s.pop();
            }
            if( s.size() != 0 ){
                prevSmaller[i] = s.top();
            }
            s.push(i);
        }
        return prevSmaller;
    }
    int maxArea( vector<int> &height ){
        int n = height.size();
        vector<int> prevSmaller = prev(height);
        vector<int> nextSmaller = next(height);

        int maxi = 0;
        for( int i = 0 ; i < n ; i++ ){
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxi = max(maxi, width * height[i]);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int m = matrix.size();        // rows
    int n = matrix[0].size();     // cols

    vector<int> height(n, 0);
    int maxi = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0')
                height[j] = 0;
            else
                height[j] += 1;
        }
        maxi = max(maxi, maxArea(height));
    }
    return maxi;
}

};
