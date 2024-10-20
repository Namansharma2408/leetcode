class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int nsi[n];
        stack<int> st;
        nsi[n-1] = n;
        st.push(n-1);
        for( int i = n - 2 ; i >= 0 ; i--){
            while( st.size() > 0 && heights[st.top()] >= heights[i]) st.pop();
            if( st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }
        int psi[n];
        stack<int> st1;
        psi[0] = -1;
        st1.push(0);
        for( int i = 1 ; i < n ; i++){
            while( st1.size() > 0 && heights[st1.top()] >= heights[i]) st1.pop();
            if( st1.size() == 0) psi[i] = -1;
            else psi[i] = st1.top();
            st1.push(i);
        }
        int maxArea = 0;
        for( int i = 0 ; i < n ; i++){
            int area = (heights[i])*(nsi[i] - psi[i] - 1);
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
