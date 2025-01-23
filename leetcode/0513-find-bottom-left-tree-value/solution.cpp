/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root){
        if( root == NULL) return 0;
        else return 1+max(levels(root->left),levels(root->right));
    }
    void leftBottom(TreeNode* root,int level,int &ans,int n){
        if( root == NULL) return;
        if(level == n-1) ans = root->val;
        leftBottom(root->right,level+1,ans,n);
        leftBottom(root->left,level+1,ans,n);

    }
    int findBottomLeftValue(TreeNode* root) {
        int n = levels(root);
        int ans = 0;
        leftBottom(root,0,ans,n);
        return ans;

    }
};
