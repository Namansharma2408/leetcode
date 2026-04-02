class Solution {
public:
    void fun(vector<int>& arr, int curr, vector<bool> &vis, bool &flag){
        if( vis[curr] ) return;
        int n = arr.size();
        if( arr[curr] == 0 ) flag = true;
        if( flag == true ) return;
        vis[curr] = true;
        if(curr+arr[curr] < n && vis[curr+arr[curr]] == false ) fun(arr,curr+arr[curr],vis,flag);
        if( flag == true ) return;
        if(curr-arr[curr] >= 0 && vis[curr-arr[curr]] == false ) fun(arr,curr-arr[curr],vis,flag);
        if( flag == true ) return;
        vis[curr] = false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        bool flag = false;
        fun(arr,start,vis,flag);
        return flag;
    }
};
