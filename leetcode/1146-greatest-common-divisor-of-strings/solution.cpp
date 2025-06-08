class Solution {
public:
    bool check(string &str,string &str1,string &str2){
        int n = str.size();
        int n1 = str1.size();
        int n2 = str2.size();
        for( int i = 0 ; i < n1/n ; i++){
            if(str != str1.substr(n*i,n)) return false;
        }
        for( int i = 0 ; i < n2/n ; i++){
            if(str != str2.substr(n*i,n)) return false;
        }
        return true;

    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(),n2 = str2.size();
        int g = gcd(n1,n2);
        for( int i = g ; i > 0 ; i--){
            string str = str1.substr(0,i);
            if( (n1%i == 0 && n2%i == 0) && check(str,str1,str2)) return str;
        }
        string s;
        return s;
    }
};
