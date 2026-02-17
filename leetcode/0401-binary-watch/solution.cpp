class Solution {
public:
    void check(vector<bool> &v,vector<string> &vs,int idx){
        int hr = 0;
        int min = 0;
        for( int i = 3 ; i >= 0 ; i-- ){
            hr *= 2;
            hr += v[i];
        }
        if( hr > 11) return;
        for( int i = 9 ; i >= 4 ; i-- ){
            min *= 2;
            min += v[i];
        }
        if( min > 59 ) return;
        string str;
        str = str + (to_string(hr));
        str.push_back(':');
        str.push_back('0');
        str.push_back('0');
        int size = str.size();
        str[size-1] += min%10;
        str[size-2] += min/10;
        vs.push_back(str);
    }
    void fun(vector<bool> &v, int turnedOn,int idx,vector<string> &vs){
        if( idx == 10 || turnedOn == 0 ){
            if( turnedOn > 0 ) return;
            check(v,vs,idx);
            return;
        }
        fun(v,turnedOn,idx+1,vs);
        v[idx] = true;
        fun(v,turnedOn-1,idx+1,vs);
        v[idx] = false;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> vs;
        if( turnedOn > 8 ) return vs;
        vector<bool> v(10,false);
        fun(v,turnedOn,0,vs);
        sort(vs.begin(),vs.end());
        return vs;
    }
};
