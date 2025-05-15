class Solution {
public:
    int longestSeq(unordered_set<int> &st,int n){
        int count = 0;
        while( st.find(n) != st.end()){
            count++,n++;
        }
        return count;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 || n == 1) return n;
        unordered_set<int> st(nums.begin(),nums.end());
        int result = -1;
        for( int i : st){
            if((st.find(i) != st.end()) && (st.find(i-1) == st.end())){
                result = max(result,longestSeq(st,i));
            }
        }
        return result;

    }
};
