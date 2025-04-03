class Solution {
public:
    vector<int> pathInZigZagTree(int n) {
        int pow2 = 1;
        while(pow2 <= n){
            pow2 *= 2;
        }
        pow2 /= 2;
        vector<int> v;
        while( n >= 1){  
            v.push_back(n); 
            int x = n - pow2;
            n = pow2 - x/2 - 1;
            pow2 /= 2;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
