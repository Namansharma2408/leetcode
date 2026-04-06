class Solution {
public:
    struct custom_hash {
        size_t operator()(const complex<int>& z) const {
            return hash<long long>()(((long long)z.real() << 32) ^ z.imag());
        }
    };
    void display(complex<int> &temp){
        cout<<temp.real()<<" "<<temp.imag()<<" \n";
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        unordered_set<complex<int>, custom_hash> st;
        for( auto p : obs ){
            complex<int> temp(p[0],p[1]);
            st.insert(temp);
        }
        int ans = 0;
        complex<int> curr(0,0);
        int n = commands.size();
        complex<int> dir(0,1);
        complex<int> leftrot(0,1);
        complex<int> rightrot(0,-1);
        for( int i = 0 ; i < n ; i++ ){
            if( commands[i] == -2 ) dir *= leftrot;
            else if( commands[i] == -1 ) dir *= rightrot;
            else {
                for( int j = 1 ; j <= commands[i] ; j++ ){
                    if( st.find(curr+dir) != st.end()) {
                        break;
                    }
                    curr += dir;
                    ans = max(ans,norm(curr));
                }
                ans = max(ans,norm(curr));
            }
            
        }
        return ans;
    }
};
