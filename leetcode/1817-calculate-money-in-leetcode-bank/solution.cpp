class Solution {
public:
    int totalMoney(int n) {
        int a = (n/7)*(56 + 7*(n/7 - 1))/2;
        a += (n%7)*( 2*(n/7) + 1 + n%7)/2;
        return a;
    }
};
