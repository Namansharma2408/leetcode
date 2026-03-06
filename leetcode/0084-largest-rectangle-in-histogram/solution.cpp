class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> ns(n);
        vector<int> ps(n);
        ns[n-1] = -1;
        ps[0] = -1;
        stack<pair<int,int>> st;
        st.push({h[0],0});
        for( int i = 1 ; i < n ; i++ ){
            if( st.empty() ) {
                ps[i] = -1;
                st.push({h[i],i});
            }
            else {
                while( !st.empty() && h[i] <= st.top().first){
                    st.pop();
                }
                if(!st.empty()) ps[i] = st.top().second;
                else ps[i] = -1;
                st.push({h[i],i});
            }
        }
        while( !st.empty() ){
            st.pop();
        }
        st.push({h[n-1],n-1});
        for( int i = n-2 ; i >= 0 ; i-- ){
            if( st.empty() ) {
                ns[i] = -1;
                st.push({h[i],i});
            }
            else {
                while( !st.empty() && h[i] <= st.top().first){
                    st.pop();
                }
                if(!st.empty()) ns[i] = st.top().second;
                else ns[i] = -1;
                st.push({h[i],i});
            }
        }
        // for( int i = 0 ; i < n ; i++ ){
        //     cout<<ps[i]<<" ";
        // } cout<<endl;
        // for( int i = 0 ; i < n ; i++ ){
        //     cout<<ns[i]<<" ";
        // } cout<<endl;
        int maxi = 0;
        for( int i = 0 ; i < n ; i++ ){
            int num = 0;
            if( ns[i] == -1 && ps[i] == -1 ) num = n*h[i];
            else if( ns[i] != -1 && ps[i] != -1 ) num = (ns[i] - ps[i] - 1)*h[i] ;
            else if( ns[i] == -1 && ps[i] != -1 ) num = (n-1 - ps[i])*h[i] ;
            else if( ns[i] != -1 && ps[i] == -1 ) num = (ns[i])*h[i] ;
            // cout<<num<<" ";
            maxi = max(maxi, num);
        }
        return maxi;
    }
};
