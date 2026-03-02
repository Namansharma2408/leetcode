class Solution {
public:
    void work(string &str, string s, int idx, vector<string> &vs, int n){
        if( idx == n ){
            vs.push_back(str);
            return;
        }
        else if( '0' <= s[idx] && s[idx] <= '9' ){
            str.push_back(s[idx]);
            work(str,s,idx+1,vs,n);
            str.pop_back();
        }
        else if( 'a' <= s[idx] && s[idx] <= 'z' ){
            str.push_back(s[idx]);
            work(str,s,idx+1,vs,n);
            str.pop_back();
            str.push_back(s[idx]+'A'-'a');
            work(str,s,idx+1,vs,n);
            str.pop_back();
        }
        else if( 'A' <= s[idx] && s[idx] <= 'Z' ){
            str.push_back(s[idx]);
            work(str,s,idx+1,vs,n);
            str.pop_back();
            str.push_back(s[idx]+'a'-'A');
            work(str,s,idx+1,vs,n);
            str.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> vs;
        string str;
        work(str,s,0,vs,s.size());
        return vs;
    }
};
