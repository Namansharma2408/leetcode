class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        if (n == 1)
            return 0;
        int mini = n;
        int maxi = -1;
        int test = 0;
        for (int i = 0; i < n; i++) {
            test++;
            if (d[i] != 'L') {
                mini = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] != 'R') {
                maxi = i;
                break;
            }
        }
        int ans = 0;
        for (int i = mini; i <= maxi; i++) {
            if (d[i] != 'S') {
                ans++;
            }
        }
        return ans;
    }
};
