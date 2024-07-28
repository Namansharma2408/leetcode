class Solution {
public:
    bool check( int mid ,vector<int> & weights,int days){
        int n = weights.size();
        int m = mid;
        int count = 1;
        for( int i = 0 ; i < n ; i++){
            if( m >= weights[i]){
                m -= weights[i];
            }
            else{
                count++;
                m = mid ;
                m -= weights[i];
            }
        }
        if(count > days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = INT_MIN;
        int high = 0;
        for( int i = 0 ; i < n ; i++){
            high += weights[i];
            if( low < weights[i]) low = weights[i];
        }
        int mincapacity = high;
        while( low <= high){
            int mid = low + (high - low)/2 ;
            if( check(mid,weights,days)){
                mincapacity = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return mincapacity;
    }
};
