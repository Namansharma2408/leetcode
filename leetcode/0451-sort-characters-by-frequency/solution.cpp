class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        for( int i = 0 ; i < n ; i++) mp[s[i]]++;       
        vector<vector<char>> buckets(s.size() + 1);
        for (auto &[ch, count] : mp) buckets[count].push_back(ch);
        s = "";
        for( int i = n ; i > 0 ; i--) for( char ch : buckets[i]) s.append(i,ch);
        return s;
    }
};
