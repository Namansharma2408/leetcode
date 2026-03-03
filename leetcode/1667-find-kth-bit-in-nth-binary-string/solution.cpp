class Solution {
public:
    char findKthBit(int n, int k) {
        // cout<<n<<" "<<k<<" "<<num<<endl;
        if( n == 1 && k == 1 ) return '0';
        int num = pow(2,n-1);
        if( k == num ) return '1';
        else if( k < num ) return findKthBit(n-1,k);
        else return (findKthBit(n-1,pow(2,n) - k) == '0' ? '1' : '0');
    }
};
