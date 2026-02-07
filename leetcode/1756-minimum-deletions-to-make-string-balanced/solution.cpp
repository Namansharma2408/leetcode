class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> A(n);
        A[0] = s[0] == 'a' ? 1 : 0 ;
        for( int i = 1 ; i < n ; i++ )
            A[i] = s[i] == 'a' ? A[i-1]+1 : A[i-1];
        vector<int> B(n);
        B[n-1] = s[n-1] == 'b' ? 1 : 0 ;
        for( int i = n-2 ; i >= 0 ; i-- )
            B[i] = s[i] == 'b' ? B[i+1]+1 : B[i+1];
        int maxi = A[0]+B[0];
        for( int i = 1 ; i < n ; i++ )
            maxi = max(maxi,A[i]+B[i]);
        return n-maxi;
    }
};
