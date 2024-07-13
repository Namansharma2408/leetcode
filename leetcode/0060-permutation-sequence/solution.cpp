class Solution {
public: 
    string helper( string str,string ans , int k){
        int n = str.size();
        if( n == 1){
            ans += str;
            return ans;
        }
        int fact = 1;
        for( int i = 2 ; i < n ; i++){
            fact *= i;
        }
        int idx = k/fact;
        if(k%fact == 0) idx--;
        char ch = str[idx];
        str = str.substr(0,idx) + str.substr(idx+1);
        if( k%fact == 0) return helper( str,ans+ch,fact);
        else return helper( str,ans+ch,k%fact);
    }
    string getPermutation(int n, int k) {
      string str ;
      for( int i = 1 ; i <=n ; i++){
        str += to_string(i);
      }
      string ans = "";     
      return helper( str,"",k);
    }
};
