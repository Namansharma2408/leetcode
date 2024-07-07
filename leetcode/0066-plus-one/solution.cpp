class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool b = false;
        int n = digits.size();
        for( int i = n-1 ; i >= 0 ; i--){
            if( digits[i] != 9){
                digits[i]++;
                for( int j = i+1 ; j < n ; j++) digits[j] =0;
                b = true;
                break;
            }
        }
        if( b == true) return digits;
        vector <int> v(n+1,0);
        if( b == false) v[0] = 1;
        return v;
        
    }
};
