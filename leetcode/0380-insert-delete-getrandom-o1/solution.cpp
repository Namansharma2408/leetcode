class RandomizedSet {
public:
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        mp[val]++;
        if( mp[val] == 1) return true;
        else return false;
    }
    
    bool remove(int val) {
        if( mp[val] == 0) {
            mp.erase(val);
            return false;
        }
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % mp.size();
        auto it = mp.begin();
        advance(it, randomIndex);
        return it->first;
    }
};             
