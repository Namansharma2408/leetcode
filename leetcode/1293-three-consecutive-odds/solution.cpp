class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int len = 0;
        for( int i = 0 ; i < n ; i++){
            if( arr[i]%2 == 1){
                len++;
                if( len == 3) return true;
            }else len = 0;
        }
        return false;
    }
};
