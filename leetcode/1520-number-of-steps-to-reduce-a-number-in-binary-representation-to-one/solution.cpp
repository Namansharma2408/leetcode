class Solution {
public:
    void addOne(string &s, int idx){
        if( idx < 0 ){
            s.insert(s.begin(),'1');
            return;
        }
        if( s[idx] == '0' ){
            s[idx] = '1';
            return;
        }
        s[idx] = '0';
        addOne(s,idx-1);
    }
    int numSteps(string s) {
        int count = 0;
        while( s != "1" ){
            if( s[s.size()-1] == '0' ) s.pop_back();
            else {
                addOne(s,s.size()-1);
            }
            count++;
        } 
        return count;
    }
};
