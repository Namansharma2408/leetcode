class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string str(n/k,' ');
        for( int i = 0 ; i < n/k ; i++){
            int hash = 0;
            for( int j = k*i ; j < (i+1)*k ; j++){
                hash = (hash + s[j] - 'a')%26;
            }
            str[i] = hash + 'a';
        }
        return str;
    }
};
