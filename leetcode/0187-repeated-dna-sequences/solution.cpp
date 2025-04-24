class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string,int> mp;
        for( int i = 0 ; i < n - 9 ; i++ ) mp[s.substr(i,10)]++;
        vector<string> ans;
        for( auto i : mp ) if( i.second > 1) ans.push_back(i.first);
        return ans;
    }
};
