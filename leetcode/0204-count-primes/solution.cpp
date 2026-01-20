class Solution {
public:
    int countPrimes(int n) {
        if( n == 0 || n == 1 || n == 2) return 0;
        vector<bool> arr(n+1,false);
        int ans = 0;
        for( int i = 2 ; i < n ; i++ ){
            if( arr[i] == false ){
                ans++;
                for( int j = i*2; j < n ; j += i ){
                    arr[j] = true;
                }
            }
        }
        return ans;
    }
};
