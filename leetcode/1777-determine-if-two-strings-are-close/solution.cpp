class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if( word1.size() != word2.size()) return false;
        unordered_map<char,int> mp1;
        for( char i : word1) mp1[i]++;
        unordered_map<char,int> mp2;
        for( char i : word2) mp2[i]++;
        for( auto i : mp1){
            char ch = i.first;
            if( mp2.find(ch) == mp2.end()) return false;
        }
        unordered_map<int,int> m2;
        for( auto i : mp1) m2[i.second]++;
        for( auto i : mp2) m2[i.second]--;
        for( auto i : m2) if( i.second != 0) return false;
        return true;
    }
};
