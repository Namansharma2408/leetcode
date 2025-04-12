class Solution {
public:
    vector<int> v;
    int n;
    vector<int> cumulative;
    int totalWeight;
    Solution(vector<int>& w) {
        v.clear();
        this->v = w;
        this->n = w.size();
        cumulative.resize(n,0);
        totalWeight = 0;
        for( int i = 0 ; i < n ; i++){
            totalWeight += v[i];
            cumulative[i] = totalWeight;
        }
    }
    
    int pickIndex() {        
        int randomValue = rand() % totalWeight;
        int selectedIndex = -1;
        for ( int i = 0 ; i < n ; i++){
            if( randomValue < cumulative[i]){
                return i;
            }
        }
        return n-1;

    }
};


