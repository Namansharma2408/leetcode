class Solution {
public:
    void back(unordered_set<string> &st,string &str,int n, bool &b){
        if( str.size() == n ){
            if( st.find(str) == st.end() ){
                b = true;
            }
            return;
        }
        if( b == true ) return;
        str.push_back('0');
        back(st,str,n,b);
        if( b == true ) return;
        str.pop_back();
        str.push_back('1');
        back(st,str,n,b);
        if( b == true ) return;
        str.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        bool b = false;
        unordered_set<string> st(nums.begin(),nums.end());
        string str;
        back(st,str,n,b);
        return str;

    }
};
