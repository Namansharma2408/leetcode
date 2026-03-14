class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        for( int i = n-1 ; i >= 0 ; i-- ){
            if( s[i] == '-' ) s.erase(i,1);
        }
        n = s.size();
        int count = 1;
        for( int i = n-1 ; i >= 0 ; i-- ){
            s[i] = toupper(s[i]);
            if( count == k && i != 0 ){
                s.insert(s.begin()+i,'-');
                count = 0;
            }

            count++;
        }
        return s;
    }
};
