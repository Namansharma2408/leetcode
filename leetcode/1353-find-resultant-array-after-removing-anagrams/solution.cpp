class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> vs = words;
        int n = words.size();
        for( int i = 0 ; i < n ; i++ ){
            sort(vs[i].begin(),vs[i].end());
        }
        set<int> st;
        st.insert(0);
        for( int i = 1 ; i < n ; i++ ){
            if(vs[i-1] != vs[i]) st.insert(i);
        }

        vs.clear();
        for( int i : st ){
            vs.push_back(words[i]);
        }
        return vs;
    }
};
