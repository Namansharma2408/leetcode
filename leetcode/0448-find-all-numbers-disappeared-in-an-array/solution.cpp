class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for( int i = 1 ; i <= n ; i++ ){
            st.insert(i);
        }
        for( int i = 0 ; i < n ; i++ ){
            st.erase(nums[i]);
        }
        vector<int> v(st.begin(),st.end());
        return v;
    }
};
