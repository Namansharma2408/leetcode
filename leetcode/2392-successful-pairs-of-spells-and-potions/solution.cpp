class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        for( int i = 0 ; i < n ; i++ ){
            // cout<<i<<" -> ";
            int lo = 0;
            int hi = m-1;
            while( lo <= hi ){
                int mid = (lo+hi)/2;
                if( (long long)spells[i]*potions[mid] < success ) lo = mid + 1;
                else hi = mid - 1;
            }
            // cout<<lo<<" "<<hi<<" ";
            spells[i] = m - lo;
            // cout<<spells[i]<<endl;
        }
        return spells;

    }
};
