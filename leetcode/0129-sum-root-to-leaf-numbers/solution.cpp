class Solution {
public:
    void down(TreeNode* root){
        if(root == NULL) return;
        if(root->left) root->left->val += root->val*10;
        if(root->right) root->right->val += root->val*10;
        down(root->left);
        down(root->right);
    }
    void sum(TreeNode* root,int &ans){
        if( root == NULL) return ;
        if(root->left == NULL && root->right == NULL) ans += root->val;
        sum(root->left,ans);
        sum(root->right,ans);
    }
    int sumNumbers(TreeNode* root) {
        if( root == NULL) return 0;
        int ans = 0;
        down(root);
        sum(root,ans);
        return ans;
    }
};
