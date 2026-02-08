class Solution {
public:
    bool isBalanced(string num) {
        int diff = 0;
        int n = num.size();
        for( int i = 0 ; i < n ; i++ ){
            if( i%2 == 0 ) diff += (num[i]-'0');
            else diff -= (num[i]-'0');
        }
        return ( diff == 0 ) ? true : false;
    }
};
