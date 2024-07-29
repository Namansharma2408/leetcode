class Solution {
public:
    int ansforone( long long mid , vector<long long> & piles){
        long long finale = 0;
        // mid = 3
        // 7 8 9 10 11
        for( int i = 0 ; i < piles.size(); i++){
            finale += (piles[i] + mid - 1) / mid; // 
            // if( piles[i]%mid == 0) finale += (long long)piles[i]/mid;
            // else  finale += (long long)piles[i]/mid + 1;
        }
        return finale;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        vector<long long> pile;
        for (int x: piles) pile.push_back(1LL * x);
        long long n = piles.size();
        long long sum = n+1;
        long long lo = 1;
        long long hi = 1E10;
        // for( int i = 0 ; i < n ; i++) if( hi < piles[i]) hi = piles[i];
        // hi += 10;
        while( lo <= hi ){ // while (lo + 1 < hi)
            long long mid = lo + (hi - lo)/2;
            if( ansforone( mid , pile) <= h){
                sum = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        cout << hi - 1 << '\n';
        return sum;

    }
};
