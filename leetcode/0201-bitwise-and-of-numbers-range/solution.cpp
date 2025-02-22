class Solution {
public:
    vector<bool> bits(int num){
        vector<bool> ans;
        while( num != 0){
            ans.push_back(num%2);
            num /= 2;
        }
        return ans;
    }
    int rangeBitwiseAnd(int left, int right) {
        if( left == right) return left;
        vector<bool> l = bits(left);
        vector<bool> r = bits(right);
        if(l.size() != r.size()) return 0;
        int n = l.size();
        for( int i = 0 ; i < n ; i++) l[i] = l[i] & r[i];
        int diff = right - left;
        int i = 0;
        while( diff != 0){
            l[i++] = 0;
            diff /= 2;
        }
        int ans = 0;
        long long p = 1;       
        for( int i = 0 ; i < n ; i++){          
            ans += p*l[i];
            p *= 2;
        }
        return ans;
    }
};
