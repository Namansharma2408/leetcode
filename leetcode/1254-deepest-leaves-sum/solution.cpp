class Solution {
public:
    int levels(TreeNode* root){
        if( root == NULL ) return 0;
        else return 1 + max(levels(root->left),levels(root->right));
    }
    void sum(TreeNode* root,int &ans,int currLevel,int n){
        if( root == NULL) return ;
        if( currLevel == n) ans += root->val;
        else{
            sum(root->left,ans,currLevel+1,n);
            sum(root->right,ans,currLevel+1,n);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        sum(root,ans,1,levels(root));
        return ans;
    }
};
