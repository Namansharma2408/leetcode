class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> visible(n,0);
        visible[n-1] = 0;
        stack<int> st;
        st.push(heights[n-1]);
        for( int i = n-2 ; i >= 0 ; i--){
            int count = 0;
            while( st.size() > 0 && heights[i] > st.top()){
                st.pop();
                count++;
            }
            if( st.size() != 0) count++;
            visible[i] = count;
            st.push(heights[i]);
        }
        return visible ;
    }
};
