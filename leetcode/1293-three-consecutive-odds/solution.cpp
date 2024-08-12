class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int a = 0;
        int n = arr.size();
        if( n < 3) return false;
        for( int i = 0 ; i < n ; i++){
            if( arr[i]%2 != 0 ){
                ++a;
                if( a == 3) return true;
            }
            else a = 0;          
        }
        return false;
    }
};
