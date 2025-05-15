class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        bool b = groups[0];
        int i = 1,j = 1;
        int n = words.size();
        while( j < n && i < n){
            if(groups[j] != b){
                words[i] = words[j];
                i++,j++;
                b = !b;
            }
            else j++;
        }
        for( int k = i ; k < n ; k++) words.pop_back();
        return words;
    }
};
