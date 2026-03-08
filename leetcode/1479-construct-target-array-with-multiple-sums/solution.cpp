class Solution {
public:
    // void display(priority_queue<int> pq){
    //     if( pq.empty() ) return;
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    //     display(pq);
    // }
    bool isPossible(vector<int>& target) {
        int n = target.size();
        long long sum = 0;
        priority_queue<int> pq;
        for( int i = 0 ; i < n ; i++ ){
            sum += target[i];
            pq.push(target[i]);
        }
        while( true ){
            int highest = pq.top();
            // cout<<highest<<" ";
            // display(pq);
            // cout<<endl;
            pq.pop();
            if( highest == 1 ) return true;
            int x = sum - highest;
            // cout<<x<<" ";
            if( highest < x  || x <= 0) return false;
            int var = highest-x;
            if( var <= 0) return false;
            var = (highest - 1)%x + 1;
            // cout<<var<<" ";
            if( var < 1 ) return false;
            pq.push(var);
            sum = sum + var - highest;
            // cout<<sum<<endl;
        }
        return false;

    }
};
