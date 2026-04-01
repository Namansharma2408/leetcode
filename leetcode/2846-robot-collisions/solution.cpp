class Solution {
public:
    struct S{
        int pos;
        int h;
        int idx;
        char dir;
    };
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<S> v(n);
        for( int i = 0 ; i < n ; i++ ){
            v[i].pos = positions[i];
            v[i].h = healths[i];
            v[i].dir = directions[i];
            v[i].idx = i;
        }
        sort(v.begin(),v.end(),[] (S a, S b){
            return a.pos < b.pos;
        });
        // for( int i = 0 ; i < n ; i++ ){
        //     cout<<v[i].pos<<" "<<v[i].h<<" "<<v[i].dir<<endl;
        // }
        stack<S> st;
        for( int i = 0 ; i < n ; i++ ){
            if( st.empty() ) st.push(v[i]);
            else if( st.top().dir == 'R' && v[i].dir == 'L' ){
                if( v[i].h < st.top().h ) st.top().h--;
                else if( v[i].h == st.top().h ) st.pop();
                else {
                    st.pop();
                    v[i].h--;
                    i--;
                } 
            } else {
                st.push(v[i]);
            }
        }
        vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().h,st.top().idx});
            st.pop();
        }
        sort(ans.begin(),ans.end(),[](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });
        vector<int> result;
        for( auto p : ans ){
            result.push_back(p.first);
        }
        return result;
    }
};
