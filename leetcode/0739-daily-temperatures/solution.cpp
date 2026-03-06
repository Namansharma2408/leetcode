class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int,int>> st;
        st.push({t[n-1],n-1});
        t[n-1] = 0;
        for( int i = n-2 ; i >= 0 ; i-- ){
            if( st.empty() ) t[i] = 0;
            else {
                int x = t[i];
                while( !st.empty() && x >= st.top().first ){
                    st.pop();
                }
                if( st.empty() ) {
                    t[i] = 0;
                    st.push({x,i});
                }
                else {
                    t[i] = st.top().second - i;
                    st.push({x,i});
                }
            }
        }
        return t;
    }
};
