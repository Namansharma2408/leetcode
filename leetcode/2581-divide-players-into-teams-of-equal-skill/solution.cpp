class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int i = 1;
        int j = n - 2;
        int a = skill[0] + skill[n-1];
        while( i < j){
            if( (skill[i] + skill[j]) != a) return -1;
            i++,j--;
        }
        long long b = 0;
        i = 0;
        j = n -1;
        while( i < j){
            b += (skill[i]*skill[j]);
            i++;
            j--;
        }
        return b;
    }
};
