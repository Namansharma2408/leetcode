class Solution {
public:
    bool check(long long mid, vector<int> & time , int totalTrips){
        long long trips = 0 ;
        long long n = time.size();
        for( int i = 0 ; i < n ; i++){
            trips += (long long)mid/time[i];
        }
        if(trips < totalTrips) return false;
        return true ;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = -1;
        long long n = time.size();
        long long mx = -1;
        for( long long i = 0 ; i < n ; i++){
            mx > time[i] ? mx = mx : mx = time[i];
        }
        long long lo = 1;
        long long hi = mx*totalTrips;
        while( lo <= hi){
            long long mid = (lo + hi)/2 ;
            if( check(mid,time,totalTrips) == true){
                l = mid ;
                hi = mid - 1 ;
            }
            else lo = mid + 1;
        }
        return l;
    }
};
