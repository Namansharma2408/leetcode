class Solution {
public:
    string toLower(string &str){
        for( char& ch: str ){
            if( 'A' <= ch && ch <= 'Z' )ch = ch - 'A' + 'a';
        }
        return str;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int k = banned.size();
        int n = paragraph.size();
        string remove = "!?',;.";
        for (char& c : paragraph) {
            if (remove.find(c) != string::npos)
                c = ' ';
        }
        stringstream ss(paragraph);
        string word;
        unordered_map<string, int> mp;
        while (ss >> word) {
            mp[toLower(word)]++;
        }

        // for (auto p : mp) {
        //     cout << p.first << " " << p.second << endl;
        // }
        for( string str : banned ){
            if(mp.find(str) != mp.end()){
                mp.erase(str);
            }
        }
        pair<string,int> ans;
        ans.first = 'abc';
        ans.second = 0;
        for( auto p : mp ){
            if( ans.second < p.second ){
                ans = p;
            }
        }
        return ans.first;
    }
};
