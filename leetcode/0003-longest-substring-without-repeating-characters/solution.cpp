class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int i = 0;
        int j = 1;
        int maxi = min(1,n);
        int curr = maxi;
        st.insert(s[0]);
        while( j < n && i < n ){
            if( st.find(s[j]) == st.end()) {
                st.insert(s[j++]);
                maxi = max(maxi,++curr);
            }else{
                while( s[i] != s[j] && i < j-1 ){
                    st.erase(s[i++]);
                }
                st.erase(s[i++]);
                st.insert(s[j++]);
                curr = st.size();
            }
        }
        return maxi;
    }
};
