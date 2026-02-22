class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int curr = -1;
        int i = 0;
        int maxi = 0;   
        while( n ){
            int x = n%2;
            if( x == 1 ){
                prev = curr;
                curr = i;
                if(prev != -1 )maxi = max(maxi,curr-prev);
            }
            i++;
            n /= 2;
        }
        // cout<<prev<<endl<<curr<<endl;
        if( prev == -1 || curr == -1 ) return 0;
        return maxi;
    }
};
