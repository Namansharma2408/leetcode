class Solution {
public:
    void generateParentheses( int i , int j , int n,vector<string> &str,string st ){
		if( i + j == 2*n){
			str.push_back(st);
			return;
		}
		if( i > j ){
			if( i < n ){
				generateParentheses(i+1,j,n,str,st + "(");
				generateParentheses(i,j+1,n,str,st + ")");
			}
			else if( i == n ){
				generateParentheses(i,j+1,n,str,st + ")");
			}
			else return;
		}
		else if( i == j ) generateParentheses(i+1,j,n,str,st + "(");
		else return;
	}
    vector<string> generateParenthesis(int n) {
        vector<string> str;
        generateParentheses(0,0,n,str,"");
        return str;
    }
};
