class Solution {
public:
    void sum(TreeNode* root,int level,vector<int> &levelSum){
        if( root == NULL) return;
        levelSum[level-1] += root->val;
        sum(root->left,level+1,levelSum);
        sum(root->right,level+1,levelSum);
    }
    int levels(TreeNode* root){
        if( root == NULL) return 0;
        else return 1 + max(levels(root->left),levels(root->right));
    }
    int maxLevelSum(TreeNode* root) {
        int n = levels(root);
        vector<int> levelSum(n);
        sum(root,1,levelSum);
        int maxi = levelSum[0];
        int idx;
        for( int i = 1 ; i < n ; i++) {
            if( maxi < levelSum[i]){
                maxi = levelSum[i];
                idx = i;
            }
        }
        return idx+1;
    }
};
