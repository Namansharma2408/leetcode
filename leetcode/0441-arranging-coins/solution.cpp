class Solution {
public:
    int arrangeCoins(int n) {
        long long lo = 0;
        long long hi = 2*sqrt(n) + 1;
        while( lo <= hi){
            long long mid = (lo+hi)/2;
            if( mid*(mid+1)/2 == n) return (int)mid;
            else if( mid*(mid+1)/2 < n) lo = mid + 1;
            else hi = mid - 1;
        }
        return (int)hi;
    }
};
