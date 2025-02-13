class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for( auto i : nums) pq.push((long long)i);
        if(pq.top() > k) return 0;
        int count = 0;
        while(true){
            if(pq.top() >= k || pq.size() < 2) return count;
            long long int x = 2*(long long)pq.top();
            pq.pop();
            if(pq.empty()) return count;
            x += pq.top();
            pq.pop();
            pq.push(x);
            count++;
        }
        return count;
    }
};
