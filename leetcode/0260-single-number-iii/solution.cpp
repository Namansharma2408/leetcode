class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> us;
        vector<int> ans(2);
        for( int i : nums){
            if( us.find(i) != us.end()) us.erase(i);
            else us.insert(i);
        }
        int j = 0;
        for( int i : us) ans[j++] = i;
        return ans;
    }
};
