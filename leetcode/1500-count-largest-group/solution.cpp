class Solution {
public:
    int sum(int n){
        int ans = 0;
        while( n != 0){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for( int i = 1 ; i <= n ; i++) mp[sum(i)]++;
        int maxi = 0;
        for( auto i : mp) cout<<i.first<<"->"<<i.second<<endl;
        for( auto i : mp) maxi = max(maxi,i.second);
        int freq = 0;
        for( auto i : mp) if( i.second == maxi ) freq++ ;
        return freq;
    }
};
