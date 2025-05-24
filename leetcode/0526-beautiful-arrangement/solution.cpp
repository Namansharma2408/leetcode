class Solution {
public:
    int ans = 0;
    void count(vector<int> &v,int n,int num){
        if( num > n ){
            ans++;
            return;
        }

        for( int i = 1 ; i <= n ; i++){
            if(v[i] == -1){
                if( num%i == 0 || i%num == 0) {
                    v[i] = num;
                    count(v,n,num+1);
                    v[i] = -1;
                }
            }
        }

    }
    int countArrangement(int n) {
        vector<int> v(n+1,-1);
        count(v,n,1);
        return ans;
    }
};
