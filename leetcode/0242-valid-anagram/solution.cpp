class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size()) return false;
        unordered_map<char,int> map;
        int n = s.size();   
        for( int i = 0 ; i < n ; i++){
            map[s[i]]++;
            map[t[i]]--;
            if( map[s[i]] == 0) map.erase(s[i]);
        }
        for( auto i : map){
            if( i.second != 0) return false;
        }
        
        return true;
    }
};
