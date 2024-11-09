class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void reverseTravel(vector<int> &w,TreeNode* root,int level,int current){
        if( root == NULL) return;
        if( level == current){
            w.push_back(root->val);
            return;
        }
        reverseTravel(w,root->right,level,current+1);
        reverseTravel(w,root->left,level,current+1);
    }
    void frontTravel(vector<int> &w,TreeNode* root,int level,int current){
        if( root == NULL) return;
        if( level == current){
            w.push_back(root->val);
            return;
        }
        frontTravel(w,root->left,level,current+1);
        frontTravel(w,root->right,level,current+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        int n = levels(root);
        for(int i = 1 ; i <= n ; i++){
            vector<int> w;
            if(i%2 == 0) reverseTravel(w,root,i,1);
            else frontTravel(w,root,i,1);
            v.push_back(w);
        }
        return v;
    }
};
