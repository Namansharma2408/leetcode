class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int i=0;
        while(i<tokens.size()){
            if(tokens[i]=="*"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int ans=second*first;
                st.push(ans);
            }else if(tokens[i]=="/"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int ans=second/first;
                st.push(ans);
            }else if(tokens[i]=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int ans=second+first;
                st.push(ans);
            }else if(tokens[i]=="-"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int ans=second-first;
                st.push(ans);
            }else{
                st.push(stoi(tokens[i]));
            }
            i++;

        }
        return st.top();
    }
};
