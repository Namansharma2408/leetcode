class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0,sum2 = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; i++){
            sum1 += s[i];
            sum2 += t[i];
        }
        sum2 += t[n];
        return (char)(sum2-sum1);
    }
};
