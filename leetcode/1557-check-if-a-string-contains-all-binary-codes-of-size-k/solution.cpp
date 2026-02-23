class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int total = 1 << k;  // 2^k
        if (n < k + total - 1) return false;
        vector<bool> seen(total, false);
        int mask = total - 1;
        int value = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            value = ((value << 1) & mask) | (s[i] == '1');
            if (i >= k - 1) {
                if (!seen[value]) {
                    seen[value] = true;
                    count++;
                    if (count == total)
                        return true;
                }
            }
        }
        return false;
    }
};
