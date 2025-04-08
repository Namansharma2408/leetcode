class Solution {
public:
    struct CompareSecond {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++) mp[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> pq;
        for( auto i : mp ) pq.push(i);
        vector<int> ans(k);

        for( int i = 0 ; i < k ; i++){
            ans[i] = (pq.top()).first;
            pq.pop();
        }
        return ans;
        
    }
};
