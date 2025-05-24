class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        int n = words.size();
        for( int i = 0 ; i < n ; i++){
            for( char ch : words[i]){
                if(ch == x){
                    v.push_back(i);
                    break;
                }
            }
        }
        return v;
    }
};
