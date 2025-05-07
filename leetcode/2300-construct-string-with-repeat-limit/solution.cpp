class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for( char ch : s) mp[ch]++;
        priority_queue<pair<char,int>> pq;
        for( auto i : mp) pq.push(i);
        s.clear();        
        while( !pq.empty()){
            auto largest = pq.top();
            pq.pop();
            int len = min(repeatLimit,largest.second);
            string str(len,largest.first);
            s.append(str);   
            pair<char,int> secondLargest;         
            if( largest.second > len ){
                if( !pq.empty()){
                    secondLargest = pq.top();
                    pq.pop();
                    string str(1,secondLargest.first);
                    s.append(str);
                }else return s;
                if( secondLargest.second > 1) pq.push({secondLargest.first,secondLargest.second-1});
                pq.push({largest.first,largest.second - len});
            }
        }
        return s;
    }
};
