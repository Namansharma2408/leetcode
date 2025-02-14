class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> us;
        vector<int> ans;
        for( int i : nums){
            if( us.find(i) != us.end()){ 
                ans.push_back(i);
                us.erase(i);
            }
            else us.insert(i);
        }
        return ans;
    }
};
