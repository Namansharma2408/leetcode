struct CompareSecond {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if(a[1] != b[1])return a[1] > b[1];
        else return a[0] > b[0];
    }
};

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        priority_queue<vector<int>, vector<vector<int>>, CompareSecond> pq;
        int n = restaurants.size();
        for( int i = 0 ; i < n ; i++ ){
            if(restaurants[i][2] < veganFriendly) continue;
            if(restaurants[i][3] > maxPrice) continue;
            if(restaurants[i][4] > maxDistance) continue;
            pq.push(restaurants[i]);
        }
        vector<int> v(pq.size());
        for( int i = pq.size() - 1  ; i >= 0 ; i--){
            v[i] = pq.top()[0];
            pq.pop();
        }
        return v;



    }
};
