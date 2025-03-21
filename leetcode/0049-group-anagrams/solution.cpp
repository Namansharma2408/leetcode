class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        for( int i = 0 ; i < n ; i++){
            string x = strs[i];
            sort(x.begin(),x.end());
            mp[x].push_back(strs[i]);
        }
        vector<vector<string>> vvs;
        for( auto i : mp) vvs.push_back(i.second);
        return vvs;
    }
};
