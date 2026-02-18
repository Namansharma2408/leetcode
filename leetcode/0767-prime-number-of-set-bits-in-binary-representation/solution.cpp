#include <bit>
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> prime = {false,false,true,true,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false};
        int ans = 0;
        for( int i = left; i <= right ; i++ ){
            ans += prime[__builtin_popcount(i)];
        }
        return ans;
    }
};
