class Solution {
public:
    bool canPlaceFlowers(vector<int>& fbd, int num) {
        int n = fbd.size();
        if( n == 1 ){
            if( fbd[0] == 0 ) return num > 1 ? false : true;
            else return num > 0 ? false : true;
        }
        if( fbd[0] == 0 && fbd[1] == 0 ) {
            fbd[0] = 1;
            num--;
        }
        for( int i = 1 ; i < n-1 ; i++ ){
            if( fbd[i] == 0 && fbd[i-1] == 0 && fbd[i+1] == 0 ) {
                fbd[i] = 1;
                num--;
            } 
        }
        if( fbd[n-1] == 0 && fbd[n-2] == 0 ) {
            fbd[n-1] = 1;
            num--;
        }
        if( num <= 0 ) return true;
        else return false;

    }
};
