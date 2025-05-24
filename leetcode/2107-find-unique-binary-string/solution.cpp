class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(),nums.end());
        int n = nums.size();
        string str(n,'0');
        if( st.find(str) == st.end()) return str;
        for( int i = 0 ; i < n ; i++){
            str[i] = '1';
            if( st.find(str) == st.end()) return str;
        }
        return str;

    }
};
