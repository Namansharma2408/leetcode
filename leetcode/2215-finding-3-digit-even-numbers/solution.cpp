class Solution {
public:
    bool find(int target,unordered_map<int,int> s){
        if(s.find(target%10) == s.end()) return false;
        s[target%10]--;
        if( s[target%10] == 0) s.erase(target%10);
        target /= 10;       
        if(s.find(target%10) == s.end()) return false;
        s[target%10]--;
        if( s[target%10] == 0) s.erase(target%10);
        target /= 10;
        if(s.find(target%10) == s.end()) return false;
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        unordered_map<int,int> s;
        for( int i : digits) s[i]++;
        for( int i = 100 ; i < 1000 ; i += 2) if( find(i,s)) ans.push_back(i);
        return ans;
    }
};
