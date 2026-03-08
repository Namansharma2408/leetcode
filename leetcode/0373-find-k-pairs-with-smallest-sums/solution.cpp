class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        set<vector<int>> st;
        vector<int> v = {nums1[0]+nums2[0],0,0};
        pq.push(v);
        st.insert(v);
        vector<vector<int>> ans;
        pair<int,int> lastIdx = {0,0};
        while( ans.size() < k && !pq.empty() ){
            vector<int> temp = pq.top();
            int idx1 = temp[1];
            int idx2 = temp[2];
            vector<int> x = {idx1,idx2};
            if( ans.size() <= 1 ) ans.push_back(x);
            else if( ans[ans.size()-1] != x ) ans.push_back(x);
            pq.pop();
            if(idx1 + 1 < m ) {
                vector<int> v1 = {nums1[idx1+1]+nums2[idx2],idx1+1,idx2};
                if(st.find(v1) == st.end() ) {
                    pq.push(v1);
                    st.insert(v1);
                }
            }
            if(idx2 + 1 < n ) {
                vector<int> v2 = {nums1[idx1]+nums2[idx2+1],idx1,idx2+1};
                if(st.find(v2) == st.end() ) {
                    pq.push(v2);
                    st.insert(v2);
                }
            }
        }
        for( int i = 0 ; i < k ; i++ ){
            ans[i][0] = nums1[ans[i][0]];
            ans[i][1] = nums2[ans[i][1]];
        }
        return ans;
    }
};
