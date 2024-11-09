class Solution {
public:
    int levels(TreeNode* root){
        if( root == NULL) return 0;
        return 1+ max(levels(root->left),levels(root->right));
    }
    void displayPreNth(vector<int> &w,TreeNode* root,int level,int nth){
        if( root == NULL) return ;
        if(level == nth){ 
            w.push_back(root->val);
            return;
        }
        displayPreNth(w,root->left,level+1,nth);
        displayPreNth(w,root->right,level+1,nth);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        int n = levels(root);
        for( int i = 1 ; i <= n ; i++){
            vector<int> w;
            displayPreNth(w,root,1,i);
            v.push_back(w);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
