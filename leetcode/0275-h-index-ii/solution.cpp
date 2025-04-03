class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0;
        int hi = n-1;
        int mid = 0;
        while( lo <= hi ){
            mid = (lo+hi)/2;
            if( citations[mid] == n-mid) return n-mid;
            else if(citations[mid] > n - mid ) hi = mid - 1;
            else lo = mid + 1;
        }
        return (n - lo);
    }
};
