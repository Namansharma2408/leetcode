class Solution {
public:
    void comb(string &str,vector<string> &result,int idx,string &digits,int n){
        if( idx == n){
            result.push_back(str);
            return;
        }
        if( digits[idx] >= '2' && digits[idx] <= '6'){
            char ch = 'a' + (digits[idx] - '2')*3;
            for( int i = 0 ; i < 3 ; i++){
                str.push_back(ch+i);
                comb(str,result,idx+1,digits,n);
                str.pop_back();
            }
        }
        if( digits[idx] == '7'){
            for( int i = 0 ; i < 4; i++){
                str.push_back('p'+i);
                comb(str,result,idx+1,digits,n);
                str.pop_back();
            }
        }
        if( digits[idx] == '8'){
            for( int i = 0 ; i < 3; i++){
                str.push_back('t'+i);
                comb(str,result,idx+1,digits,n);
                str.pop_back();
            }
        }
        if( digits[idx] == '9'){
            for( int i = 0 ; i < 4; i++){
                str.push_back('w'+i);
                comb(str,result,idx+1,digits,n);
                str.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string str;
        int n = digits.size();
        if( n == 0) return result;
        comb(str,result,0,digits,n);
        return result;
    }
};
