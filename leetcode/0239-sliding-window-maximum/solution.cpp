class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if( k == 1) return nums;
        int n = nums.size();
        int nge[n];
        stack<int> st;
        nge[n-1] = n;
        st.push(n-1);
        for(int i = n-2 ; i >= 0 ; i--){
            while( st.size() > 0 && nums[st.top()] <= nums[i] )st.pop();
            if(st.size() == 0) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }
        vector<int> v;
        int j = 0;
        for( int i = 0 ; i < n-k+1 ; i++){
            if( j < i) j = i;
            int mx = nums[j];
            while( j < i+k){
                mx = nums[j];
                if( nge[j] >= i+k) break;
                j = nge[j];
            }
            v.push_back(mx);
        }
        return v;
    }
};
