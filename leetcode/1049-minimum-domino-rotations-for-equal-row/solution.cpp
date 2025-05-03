class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        auto check = [&](int target) -> int {
            int rotateTop = 0, rotateBottom = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] != target && bottoms[i] != target)
                    return -1;
                if (tops[i] != target)
                    rotateTop++;      // rotate to bring target to top
                if (bottoms[i] != target)
                    rotateBottom++;   // rotate to bring target to bottom
            }
            return min(rotateTop, rotateBottom);
        };
        int ans = check(tops[0]);
        if (ans != -1) return ans;
        return check(bottoms[0]);
    }

};
