class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if( n%groupSize != 0 ) return false;
        cout<<"1st step"<<endl;
        // if( groupSize == 1 ) return true;
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ ){
            mp[hand[i]]++;
        }

        while(!mp.empty()){
            auto it = mp.begin();
            int x = it->first;
            for( int i = x ; i < x + groupSize ; i++ ){
                if( mp[i] == 0 ) return false;
                mp[i]--;
                if( mp[i] == 0 ) mp.erase(i);
            } 
        }

        return true;
    }
};
