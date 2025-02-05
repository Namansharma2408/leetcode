class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        int n = arr.size();
        for( int i = 0 ; i < n ; i++) map[arr[i]]++;
        unordered_set<int> set;
        for( auto x : map){
            if( set.find(x.second) != set.end()) return false;
            else set.insert(x.second);
        }
        return true;
    }
};
