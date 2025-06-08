class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> v = {0,0,0,0,0};
        num.insert(num.begin(),v.begin(),v.end());
        int carry = 0;
        int n = num.size();
        for( int i = n-1 ; i >= 0 ; i--){
            num[i] += (k%10) + carry;
            carry = num[i]/10;
            num[i] %= 10;
            k /= 10;
        }
        int i = 0;
        for( i = 0 ; i < n ; i++){
            if(num[i] != 0) break;
        }
        num.erase(num.begin(),num.begin()+i);
        return num;
    }
};
