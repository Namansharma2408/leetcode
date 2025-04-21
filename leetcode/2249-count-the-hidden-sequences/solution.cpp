class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long int sum = 0;
        vector<long long> vec(n);
        for(int i = 0 ; i < n ; i++) {
            sum += differences[i];
            vec[i] = sum;
        }
        vector<long long> v = {lower,upper};
        for( int i = 0 ; i < n ; i++){
            if( vec[i] + v[0] < lower ) v[0] = lower - vec[i];
            if( vec[i] + v[1] > upper ) v[1] = upper - vec[i];
        }
        long long int ans = v[1]-v[0]+1;
        if( v[0] > v[1]) return 0;        
        else return (int)(ans);
    }
};
