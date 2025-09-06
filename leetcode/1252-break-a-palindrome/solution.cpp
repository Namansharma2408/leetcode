class Solution {
public:
    string breakPalindrome(string s) {
        int n = (int)s.size();
        if (n == 1)
            return "";

        // Try to change the leftmost non-'a' in the first half to 'a'
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }

        // If all chars in the first half are 'a', change the last char to 'b'
        s[n - 1] = 'b';
        return s;
    }
};
