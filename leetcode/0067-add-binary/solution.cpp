class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int m = a.size();
        int n = b.size();
        string str;
        int p = max(m,n);
        int carry = 0;
        for( int i = 0 ; i < p ; i++ ){
            int ch = 0;
            if( i < m ) ch += a[i] - '0';
            if( i < n ) ch += b[i] - '0';
            ch += carry;
            carry = ch/2;
            ch %= 2;
            str.push_back('0'+ch);
        }
        if( carry > 0 ) str.push_back('0'+carry);
        reverse(str.begin(),str.end());
        return str;
    }
};
