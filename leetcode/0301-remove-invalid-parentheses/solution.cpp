class Solution {
public:
    set<string> vstr;
    void removal(string &input,int idx,string &output,int n,int maxi,int &currOpen,int &currClose){
        if( idx == n ){
            if( currOpen == currClose && currOpen == maxi){
                vstr.insert(output);
            }
            return;
        }
        if( input[idx] == '(') {
            if( currOpen < maxi){
                output.push_back('(');
                currOpen++;
                removal(input,idx+1,output,n,maxi,currOpen,currClose);
                currOpen--;
                output.pop_back();
            }
            removal(input,idx+1,output,n,maxi,currOpen,currClose);         
        }
        else if( input[idx] == ')') {
            if( currOpen > currClose){
                output.push_back(')');
                currClose++;
                removal(input,idx+1,output,n,maxi,currOpen,currClose);
                currClose--;
                output.pop_back();
            }
             
            else if( currOpen < currClose) return;
            removal(input,idx+1,output,n,maxi,currOpen,currClose);

        }
        else {
            output.push_back(input[idx]);
            removal(input,idx+1,output,n,maxi,currOpen,currClose);
            output.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string output = "";
        int n = s.size();
        stack<char> st;
        int open = 0;
        int close = 0;
        for( int i = 0 ; i < n ; i++){
            if( s[i] == '(' ) {
                st.push('(');
                open++;
            }
            else if( s[i] == ')' && open > close){
                st.pop();
                close++;
            }
        }
        int maxi = close;
        vstr.clear();
        int currOpen = 0;
        int currClose = 0;
        removal(s,0,output,n,maxi,currOpen,currClose);
        vector<string> v(vstr.begin(),vstr.end());
        if( v.size() == 0)v.push_back("");
        return v;
    }
};
