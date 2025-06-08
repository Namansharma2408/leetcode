class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> v(n);
        int i = 0;
        while( candies != 0 ){
            v[i%n] += min(candies,i+1);
            candies -= i+1;
            i++;
            if( candies <= 0) break;
        }
        return v;
    }
};
