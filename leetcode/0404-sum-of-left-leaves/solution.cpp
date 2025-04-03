class Solution {
public:
    void leftSum(TreeNode* root,int &ans){
        if( root == NULL) return;
        if(root->left != NULL){
            if(root->left->left == NULL && root->left->right == NULL){
                ans += root->left->val;
            }
        }
        leftSum(root->left,ans);
        leftSum(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        leftSum(root,ans);
        return ans;
    }
};
