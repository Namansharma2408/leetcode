// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long lo = 0;
        long hi = n - 1;
        int mid;
        while( lo <= hi){
            mid = (lo + hi)/2;
            if( isBadVersion(mid) == false) lo = mid + 1;
            else hi = mid - 1;
        }
        return (int)lo;
    }
};
