class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for( int i = 0 ; i < n ; i++ ){
            pq.push(stones[i]);
        }
        while( !pq.empty() ){
            int a = pq.top();
            pq.pop();
            if( pq.empty() ) return a;
            int b = pq.top();
            pq.pop();
            if( a != b ){
                a -= b;
                if( a < 0 ) a *= -1;
                pq.push(a);
            }
        }
        return 0;
    }
};
